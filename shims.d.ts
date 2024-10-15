declare namespace sengo2VisionSensor {
  //% shim=tosee_sentry::sengo2_Begin
  function sengo2_Begin(mode: number, addr: number): number;

  //% shim=tosee_sentry::sengo2_LedSetColor
  function sengo2_LedSetColor(
    detected_color: number,
    undetected_color: number,
    leval: number
  ): number;

  //% shim=tosee_sentry::sengo2_CameraSetAwb
  function sengo2_CameraSetAwb(wb: number): number;

  //% shim=tosee_sentry::sengo2_SetParamNum
  function sengo2_SetParamNum(vision_type: number, max_num: number): number;

  //% shim=tosee_sentry::sengo2_SetParam
  function sengo2_SetParam(
    vision_type: number,
    param: Buffer,
    param_id: number
  ): number;

  //% shim=tosee_sentry::sengo2_VisionSetStatus
  function sengo2_VisionSetStatus(status: number, vision_type: number): number;

  //% shim=tosee_sentry::sengo2_GetValue
  function sengo2_GetValue(
    vision_type: number,
    object_info: number,
    obj_id: number
  ): number;

  //% shim=tosee_sentry::sengo2_GetQrCodeValue
  function sengo2_GetQrCodeValue(): string;
}
