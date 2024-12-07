function kVisionQrCode() {
    Sengo2VisionSensor.VisionSetStatus(sengo2_status.Enable, sengo_vision_e.kVisionQrCode)
    while (true) {
        count = Sengo2VisionSensor.Detected(sengo_vision_e.kVisionQrCode)
        serial.writeValue("count", count)
        if (count) {
            for (let index = 0; index < count; index++) {
                serial.writeValue("x", Sengo2VisionSensor.QrcodeValue(sentry_qr_info_e.kXValue, count))
                serial.writeValue("y", Sengo2VisionSensor.QrcodeValue(sentry_qr_info_e.kXValue, count))
                serial.writeValue("w", Sengo2VisionSensor.QrcodeValue(sentry_qr_info_e.kXValue, count))
                serial.writeValue("h", Sengo2VisionSensor.QrcodeValue(sentry_qr_info_e.kXValue, count))
                serial.writeString(Sengo2VisionSensor.QrcodeValueString())
            }
        }
    }
    Sengo2VisionSensor.VisionSetStatus(sengo2_status.Disable, sengo_vision_e.kVisionQrCode)
}
function kVisionColor() {
    Sengo2VisionSensor.VisionSetStatus(sengo2_status.Enable, sengo_vision_e.kVisionColor)
    Sengo2VisionSensor.SetParamNum(sengo_vision_e_2.kVisionColor, 4)
    Sengo2VisionSensor.SetColorParam(10, 50, 3, 4, 1)
    Sengo2VisionSensor.SetColorParam(40, 50, 3, 4, 2)
    Sengo2VisionSensor.SetColorParam(60, 50, 3, 4, 3)
    Sengo2VisionSensor.SetColorParam(80, 50, 3, 4, 4)
    while (true) {
        count = Sengo2VisionSensor.Detected(sengo_vision_e.kVisionColor)
        if (count) {
            serial.redirectToUSB()
            serial.writeValue("count", count)
            for (let index = 0; index < count; index++) {
                serial.writeValue("l", Sengo2VisionSensor.ColorRcgValue(sentry_color_info_e.kLabel, 1))
                serial.writeValue("r", Sengo2VisionSensor.ColorRcgValue(sentry_color_info_e.kRValue, 1))
                serial.writeValue("g", Sengo2VisionSensor.ColorRcgValue(sentry_color_info_e.kGValue, 1))
                serial.writeValue("b", Sengo2VisionSensor.ColorRcgValue(sentry_color_info_e.kBValue, 1))
            }
            serial.redirect(
                SerialPin.P14,
                SerialPin.P13,
                BaudRate.BaudRate9600
            )
        }
    }
    Sengo2VisionSensor.VisionSetStatus(sengo2_status.Disable, sengo_vision_e.kVisionColor)
}
let count = 0
serial.redirect(
    SerialPin.P14,
    SerialPin.P13,
    BaudRate.BaudRate9600
)
Sengo2VisionSensor.Begin(sentry_mode_e.kSerialMode, sengo2_addr_e.ADDR1)
basic.forever(function () {
    kVisionColor()
    basic.pause(1000)
    kVisionQrCode()
})
