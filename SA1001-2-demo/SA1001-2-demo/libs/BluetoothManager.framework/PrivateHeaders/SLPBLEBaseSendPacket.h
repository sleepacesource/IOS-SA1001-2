//
//  SLPBLESendData.h
//  Sleepace
//
//  Created by Martin on 6/6/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SLPCommon/SLPCommon.h>

@class SLPBLEBaseSendPacket;
@protocol SLPBLEBaseSendPacketDelegate <NSObject>
//超时
- (void)sendPacketTimeout:(SLPBLEBaseSendPacket *)sendPacket;
@end

@interface SLPBLEBaseSendPacket : NSObject
//新协议才有的
@property (nonatomic,assign) SLPDeviceTypes deviceType;//设备类型 目前binatone和新协议才有 其他有的没有 binatone做了特殊处理
@property (nonatomic,weak) id<SLPBLEBaseSendPacketDelegate> delegate;
@property (nonatomic,assign) NSInteger protocalType;//协议类型 对应版本 //SLPBLEProtocalType
@property (nonatomic,assign) NSInteger framType;//帧类型 SLPFramTypes
@property (nonatomic,assign) NSInteger messageType;//消息类型
@property (nonatomic,assign) NSInteger sequence;//消息序号
@property (nonatomic,strong) NSData *content;//消息内容 //纯内容，一些参数
//控制用的
//自定义的消息类型~ 和蓝牙的消息一一对应
@property (nonatomic,assign) NSInteger uniqMessageType; //SLPBLEMessagetUniqTypes
@property (nonatomic,assign) CGFloat timeout;//超时时间
@property (nonatomic,copy) SLPTransforCompletion completion;

- (NSData *)packet;

- (void)fire;
- (void)invalidate;

@end
