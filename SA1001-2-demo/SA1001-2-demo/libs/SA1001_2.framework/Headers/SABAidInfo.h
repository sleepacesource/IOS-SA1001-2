//
//  SABAidInfo.h
//  SDK
//
//  Created by Martin on 12/11/18.
//  Copyright © 2018年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SABAidInfo : NSObject
@property (nonatomic,assign) UInt8 volume;//音量 音量(0-16) 0:静音
@property (nonatomic,assign) UInt8 brightness;//灯光亮度 (0-100)
@property (nonatomic, assign) UInt8 r;//灯光颜色r分量 0-255
@property (nonatomic, assign) UInt8 g;//灯光颜色g分量 0-255
@property (nonatomic, assign) UInt8 b;//灯光颜色b分量 0-255
@property (nonatomic, assign) UInt8 w;//灯光颜色W分量 0-255  (目前W分量为0)
@property (nonatomic, assign) UInt8 aidStopDuration;//辅助停止时长 单位：分钟
@property (nonatomic, assign) UInt8 aromaRate;//香薰速率 0：关 1-3：三挡速率
@end

NS_ASSUME_NONNULL_END
