//
//  SLPBLEManager+SA1001_2.h
//  SA1001_2
//
//  Created by Martin on 12/11/18.
//  Copyright © 2018年 Martin. All rights reserved.
//

#import <BluetoothManager/BluetoothManager.h>
#import <SLPCommon/SLPCommon.h>
#import "SABDeviceInfo.h"
#import "SABWorkStatus.h"
#import "SABUpgradeInfo.h"
#import "SABAlarmInfo.h"
#import "SABNightLightInfo.h"
#import "SABAidInfo.h"
#import "SABTimeAromaInfo.h"
#import "SABCenterKey.h"
#import "SABPINCode.h"

NS_ASSUME_NONNULL_BEGIN

@interface SLPBLEManager (SA1001_2)

/**
 连接设备
 @param peripheral 蓝牙句柄
 @param handle 回调 data类型为SABDeviceInfo
 */
- (void)SAB:(CBPeripheral *)peripheral loginCallback:(SLPTransforCallback)handle;

/**
 时间校准
 @param peripheral 蓝牙句柄
 @param timeInfo 时间信息
 @param timeout 超时（单位秒）
 @param handle 回调 data类型为SABDeviceInfo
 */
- (void)SAB:(CBPeripheral *)peripheral syncTimeInfo:(SLPTimeInfo*)timeInfo timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 获取设备信息
 @param peripheral 蓝牙句柄
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral getDeviceInfoTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 设备初始化
 @param peripheral 蓝牙句柄
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral deviceInitTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;


/**
 中心按键功能设置
 @param peripheral 蓝牙句柄
 @param lightEnable 灯开关 （颜色为助眠灯颜色）
 @param musicEnable 音乐开关 音乐为助眠音乐）
 @param aromaEnable 香薰开关 香薰速率为助眠香薰速率
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setCenterKey:(BOOL)lightEnable musicEnable:(BOOL)musicEnable aromaEnable:(BOOL)aromaEnable timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 获取中心键
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调 返回SABCenterKey
 */
- (void)SAB:(CBPeripheral *)peripheral getCenterKeyTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 删除所有定时香薰
 @param peripheral 蓝牙句柄
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral removeAllTimeAromaTimeout:(CGFloat)timeout  callback:(SLPTransforCallback)handle;


/**
 删除定时香薰
 @param peripheral 蓝牙句柄
 @param aromaID 香薰ID
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral deleteTimeAroma:(UInt64)aromaID timeout:(CGFloat)timeout  callback:(SLPTransforCallback)handle;


/**
 修改定时香薰 有则改，无则加
 @param peripheral 蓝牙句柄
 @param timeAromaList 定时香薰列表
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral editeTimeAromaList:(NSArray<SABTimeAromaInfo *> *)timeAromaList timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 获取定时香薰
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调 返回 NSArray<SLPSABGetTimeAromaList *>
 */
- (void)SAB:(CBPeripheral *)peripheral getTimeAromaTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 工作状态查询
 @param peripheral 蓝牙句柄
 @param timeout 超时（单位秒）
 @param handle 回调 data类型为SABWorkStatus
 */
- (void)SAB:(CBPeripheral *)peripheral getWorkStatusTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 设备升级
 @param peripheral 蓝牙句柄
 @param data 升级数据
 @param timeout 超时（单位秒）
 @param handle 回调 data类型为SABUpgradeInfo
 */
- (void)SAB:(CBPeripheral *)peripheral deviceUpgrade:(NSData *)data timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 添加或修改闹铃
 @param peripheral 蓝牙句柄
 @param alarmInfo 闹钟信息
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral alarmConfig:(SABAlarmInfo *)alarmInfo
       timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 获取闹钟列表
 @param peripheral 蓝牙句柄
 @param timeout 超时（单位秒）
 @param handle 回调 返回 NSArray<SABAlarmInfo *>
 */
- (void)SAB:(CBPeripheral *)peripheral getAlarmListTimeout:(CGFloat)timeout completion:(SLPTransforCallback)handle;

/**
 打开闹铃
 @param peripheral 蓝牙句柄
 @param alarmID 闹钟ID
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnAlarm:(UInt64)alarmID timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 关闭闹铃
 @param peripheral 蓝牙句柄
 @param alarmID 闹铃ID
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOffAlarm:(UInt64)alarmID timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 删除闹铃
 @param peripheral 蓝牙句柄
 @param alarmID 闹铃ID
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral delAlarm:(UInt64)alarmID timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 闹铃预览
 @param peripheral 蓝牙句柄
 @param volume 音量大小 闹钟最大音量(0-16) 0:静音
 @param brightness 灯光亮度 灯光最大亮度(0-100) 0:不亮
 @param aromaRate 香薰速率 0：关 1-3：三挡速率
 @param musicID 音乐编号
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral startAlarmRreviewVolume:(UInt8)volume brightness:(UInt8)brightness aromaRate:(UInt8)aromaRate musicID:(UInt16)musicID timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 退出闹铃预览
 @param peripheral 蓝牙句柄
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral stopAlarmRreviewTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 启用闹铃 只启用, 不开闹钟
 @param peripheral 蓝牙句柄
 @param alarmID 闹铃ID
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral enableAlarm:(UInt64)alarmID timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 禁用闹铃 当前该闹钟在运行，则停止
 @param peripheral 蓝牙句柄
 @param alarmID 闹铃ID
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral disableAlarm:(UInt64)alarmID timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 设置小夜灯
 @param peripheral 蓝牙句柄
 @param info 小夜灯信息
 @param timeout 超时（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral nightLightConfig:(SABNightLightInfo *)info timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;


/**
 控制香薰
 @param peripheral 蓝牙句柄
 @param rate 香薰速率 0-3 0：关闭
 @param timeout 超时时间（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setAroma:(UInt8)rate timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 打开白光
 @param peripheral 蓝牙句柄
 @param light 灯光结构
 @param brightness 灯光亮度(0-100) 0:不亮
 @param timeout 超时时间（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnWhiteLight:(SLPLight *)light brightness:(UInt8)brightness timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 打开彩光
 @param peripheral 蓝牙句柄
 @param light 灯光结构
 @param brightness 灯光亮度(0-100) 0:不亮
 @param timeout 超时时间（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnColorLight:(SLPLight *)light brightness:(UInt8)brightness timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 打开流光

 @param peripheral 蓝牙句柄
 @param brightness 灯光亮度(0-100) 0:不亮
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnStreamerBrightness:(UInt8)brightness timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 灯光亮度调节
 @param peripheral 蓝牙句柄
 @param brightness 灯光亮度(0-100) 0:不亮
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral lightBrightness:(UInt8)brightness timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 关灯
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOffLightTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 打开音乐
 @param peripheral 蓝牙句柄
 @param musicID 音乐ID
 @param volume 音量 音量(0-16) 0:静音
 @param playMode //播放模式 0：顺序播放 1: 随机播放 2: 单曲播放
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnMusic:(UInt16)musicID volume:(UInt8)volume playMode:(UInt8)playMode timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 停止音乐
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOffMusicTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 暂停音乐
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral pauseMusicTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 设置音量
 @param peripheral 蓝牙句柄
 @param volume 音量(0-16) 0:静音
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setMusicVolume:(UInt8)volume timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 设置播放模式
 @param peripheral 蓝牙句柄
 @param playMode 播放模式 0：顺序播放 1: 随机播放 2: 单曲播放
 @param musicID 音乐ID
 @param volume 音量
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setPlayMode:(UInt8)playMode  musicID:(UInt16)musicID volume:(UInt8)volume timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 助眠操作
 @param peripheral 蓝牙句柄
 @param operation 操作类型 0x00: 正常操作  0x01: 重新开启  0x02: 停止助眠  0x03: 暂停助眠  0x04: 恢复助眠  0x05: 缓慢停止辅助
 @param lightOperation 灯开关 0: 关 1: 开 0xFF: 保持原状态
 @param musicOperation 音乐开关 0: 停止 1: 播放 2: 暂停 0xFF: 保持原状态
 @param aromaOperaion 香薰开关 0: 关 1: 开 0xFF: 保持原状态
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setSleepAidWithOperation:(UInt8)operation lightOperation:(UInt8)lightOperation musicOperation:(UInt8)musicOperation aromaOpertaion:(UInt8)aromaOperaion timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 打开助眠灯
 @param peripheral 蓝牙句柄
 @param light 灯结构
 @param brightness 灯光亮度(0-100) 0:不亮
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnSleepAidLight:(SLPLight *)light brightness:(UInt8)brightness timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 助眠灯亮度调节
 @param peripheral 蓝牙句柄
 @param brightness 灯光亮度(0-100) 0:不亮
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setSleepAidLightBrightness:(UInt8)brightness timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 打开助眠音乐
 @param peripheral 蓝牙句柄
 @param musicID 音乐ID
 @param volume 音量(0-16) 0:静音
 @param playMode 播放模式 0：顺序播放 1: 随机播放 2: 单曲播放
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOnsleepAidMusic:(UInt16)musicID volume:(UInt8)volume playMode:(UInt8)playMode timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 停止助眠音乐
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral turnOffSleepAidMusic:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 助眠音量调节
 @param peripheral 蓝牙句柄
 @param volume 音量(0-16) 0:静音
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setSleepAidMusicVolume:(UInt8)volume timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;


/**
 设置助眠香薰
 @param peripheral 蓝牙句柄
 @param rate 香薰速率 0-3 0：关闭
 @param timeout 超时时间（单位秒）
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral setAssistAroma:(UInt8)rate timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/**
 保存助眠配置信息

 @param peripheral 蓝牙句柄
 @param info 助眠信息
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral sleepAidConfig:(SABAidInfo *)info timeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;


/**
 设置PIN码功能
 @param peripheral 蓝牙句柄
 @param enable 是否开启PIN码功能
 @param timeout 超时时间（单位秒)
 @param handle 回调
 */
- (void)SAB:(CBPeripheral *)peripheral configurePINWithEnable:(BOOL)enable timeout:(CGFloat)timeout completion:(SLPTransforCallback)handle;

/**
 获取PIN码功能
 @param peripheral 蓝牙句柄
 @param timeout 超时时间（单位秒)
 @param handle 回调 返回SABPINCode
 */
- (void)SAB:(CBPeripheral *)peripheral getPINCodeTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;
@end

NS_ASSUME_NONNULL_END
