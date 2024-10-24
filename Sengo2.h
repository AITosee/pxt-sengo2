// Copyright 2021 Tosee Intelligence (hangzhoou) co.,ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SENGO2_H_
#define SENGO2_H_

#include "lib/SentryFactory.h"

namespace tosee_sentry {

#define SENGO2_DEVICE_ID 0x07

class Sengo2 : public SentryFactory {
 public:
  Sengo2(uint32_t address = 0x60)
      : SentryFactory(address, SENGO2_DEVICE_ID, product_vision_state_,
                      kVisionMaxType, kVisionQrCode) {}
  virtual ~Sengo2() {}
  Sengo2(const Sengo2&) = delete;
  Sengo2& operator=(const Sengo2&) = delete;

    enum sengo_vision_e
    {
      //% block="Color"
      kVisionColor = 1,
      //% block="Blob"
      kVisionBlob = 2,
      //% block="AprilTag"
      kVisionAprilTag = 3,
      //% block="Line"
      kVisionLine = 4,
      //% block="Learning"
      kVisionLearning = 5,
      //% block="Card"
      kVisionCard = 6,
      //% block="Face"
      kVisionFace = 7,
      //% block="20Class"
      kVision20Classes = 8,
      //% block="QrCode"
      kVisionQrCode = 9,
      //% block="Motion"
      kVisionMotionDetect = 11,
      //% blockHidden=true
      kVisionMaxType,
    };

  /* SentryFactory label */
  enum { kUnknownLabel = 0 };
  /* Sentry card label */
  enum card_label_e {
      //% block="Forward"
      kCardForward = 1,
      //% block="Left"
      kCardLeft = 2,
      //% block="Right"
      kCardRight = 3,
      //% block="Turn Around"
      kCardTurnAround = 4,
      //% block="Park"
      kCardPark = 5,
      //% block="Green Light"
      kCardGreenLight = 6,
      //% block="Red Light"
      kCardRedLight = 7,
      //% block="Speed 40"
      kCardSpeed40 = 8,
      //% block="Speed 60"
      kCardSpeed60 = 9,
      //% block="Speed 80"
      kCardSpeed80 = 10,
  };
  /* SentryFactory 20 classes label */
  enum class20_label_e {
      //% block="Airplane"
      kAirplane = 1,
      //% block="Bicycle"
      kBicycle = 2,
      //% block="Bird"
      kBird = 3,
      //% block="Boat"
      kBoat = 4,
      //% block="Bottle"
      kBottle = 5,
      //% block="Bus"
      kBus = 6,
      //% block="Car"
      kCar = 7,
      //% block="Cat"
      kCat = 8,
      //% block="Chair"
      kChair = 9,
      //% block="Cow"
      kCow = 10,
      //% block="DiningTable"
      kDiningTable = 11,
      //% block="Dog"
      kDog = 12,
      //% block="Horse"
      kHorse = 13,
      //% block="MotorBike"
      kMotorBike = 14,
      //% block="Person"
      kPerson = 15,
      //% block="PottedPlant"
      kPottedPlant = 16,
      //% block="Sheep"
      kSheep = 17,
      //% block="Sofa"
      kSofa = 18,
      //% block="Train"
      kTrain = 19,
      //% block="TvMonitor"
      kTvMonitor = 20
  };
  /* SentryFactory color label */
  enum color_label_e {
      //% block="Black"
      kColorBlack = 1,
      //% block="White"
      kColorWhite = 2,
      //% block="Red"
      kColorRed = 3,
      //% block="Green"
      kColorGreen = 4,
      //% block="Blue"
      kColorBlue = 5,
      //% block="Yellow"
      kColorYellow = 6
  };
  /* AprilTag vision mode */
  enum apriltag_vision_mode_e {
      //% block="16H5"
    kVisionModeFamily16H5 = 0,
    //% block="25H9"
    kVisionModeFamily25H9 = 1,
    //% block="36H11"
    kVisionModeFamily36H11 = 2
  };
  /**
   * @brief  begin vision.
   * @param  vision_type: vision type.
   * @retval SENTRY_OK:  success
   *         other:  error
   */
  uint8_t VisionBegin(sengo_vision_e vision_type) {
    return SentryFactory::VisionBegin((int)vision_type);
  }
  /**
   * @brief  end vision.
   * @param  vision_type: vision type.
   * @retval SENTRY_OK:  success
   *         other:  error
   */
  uint8_t VisionEnd(sengo_vision_e vision_type) {
    return SentryFactory::VisionEnd((int)vision_type);
  }
  /**
   * @brief  Set max detect object number.
   * @param  vision_type: vision type.
   * @param  param:  vision parameter
   * @param  max_num:  max number
   * @retval SENTRY_OK:  success
   *         other:  error
   */
  uint8_t SetParamNum(sengo_vision_e vision_type, int max_num) {
    return SentryFactory::SetParamNum((int)vision_type, max_num);
  }
  /**
   * @brief  write vision parameter.
   * @param  vision_type: vision type.
   * @param  param:  vision parameter
   * @param  param_id:  parameter id
   * @retval SENTRY_OK:  success
   *         other:  error
   */
  uint8_t SetParam(sengo_vision_e vision_type, sentry_object_t* param,
                   int param_id = 1) {
    return SentryFactory::SetParam((int)vision_type, param, param_id);
  }
  /**
   * @brief  get vision result data, this function will update vision
   *         result automatically.
   * @param  vision_type: vision type.
   * @param  obj_info:  object information
   * @retval information value
   */
  int GetValue(sengo_vision_e vision_type, sentry_obj_info_e obj_info,
               int obj_id = 1) {
    return SentryFactory::GetValue((int)vision_type, obj_info, obj_id);
  }

  bool VisionGetStatus(sengo_vision_e vision_type) {
    return SentryFactory::VisionGetStatus((int)vision_type);
  }

  uint8_t VisionSetMode(sengo_vision_e vision_type, int mode) {
    return SentryFactory::VisionSetMode((int)vision_type, mode);
  }

  uint8_t VisionGetMode(sengo_vision_e vision_type, int *mode) {
    return SentryFactory::VisionGetMode((int)vision_type, mode);
  }

  uint8_t VisionSetLevel(sengo_vision_e vision_type,
                         sentry_vision_level_e level) {
    return SentryFactory::VisionSetLevel((int)vision_type, level);
  }

  uint8_t VisionGetLevel(sengo_vision_e vision_type,
                         sentry_vision_level_e *level) {
    return SentryFactory::VisionGetLevel((int)vision_type, level);
  }

  uint8_t VisionSetDefault(sengo_vision_e vision_type) {
    return SentryFactory::VisionSetDefault((int)vision_type);
  }

  uint8_t UpdateResult(sengo_vision_e vision_type) {
    return SentryFactory::UpdateResult((int)vision_type);
  }

 private:
  sentry_vision_state_t* product_vision_state_[kVisionMaxType - 1] = {nullptr};
};

}  // namespace tosee_sentry

#endif /* SENGO2_H_ */
