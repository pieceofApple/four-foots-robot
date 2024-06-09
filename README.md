# four-foots-robot

🤖 **四足机器人项目**

**项目描述**：
本项目基于开源项目进行 SolidWorks 建模，并采用 MSP430F5529 制作。

## 硬件组件
- **MSP430F5529**: 主控制器
- **HC-05**: 蓝牙模块
- **MPU6050**: 六轴传感器
- **SG92R**: 舵机
- **ESP32CAM**: 摄像头模块
- **ST7735**: 彩屏模块 (后续加入，当前讲解书中未包含)
- **4000mAh-5V 电池**: 电源

## 功能介绍
- 🌐 **无线控制**：通过 HC-05 蓝牙模块实现无线控制。
- 🎥 **实时视频**：使用 ESP32CAM 进行实时视频传输。
- 📐 **精确测量**：MPU6050 提供六轴传感数据。
- 🚀 **高效驱动**：SG92R 舵机用于四足运动控制。
- 🌈 **显示**：计划后续加入 ST7735 彩屏进行状态显示。

## 开发工具
- **SolidWorks**: 3D建模
- **Code Composer Studio (CCS)**: MSP430F5529 编程和调试

## 电路图和设计
![image](https://github.com/pieceofApple/four-foots-robot/assets/116827010/e4aac959-82cb-461b-aae7-86a5f60cc94b)


## 连接示例
参考电路图
```plaintext
MSP430F5529     HC-05      MPU6050    SG92R   ESP32CAM  ST7735    电池
VCC             VCC        VCC        VCC     VCC       VCC       +
GND             GND        GND        GND     GND       GND       -
TX              RX         -          -       -         -         -
RX              TX         -          -       -         -         -
SCL             -          SCL        -       -         SCL       -
SDA             -          SDA        -       -         SDA       -
