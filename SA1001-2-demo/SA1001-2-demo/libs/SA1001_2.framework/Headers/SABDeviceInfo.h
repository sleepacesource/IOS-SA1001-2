//
//  SABDeviceInfo.h
//  SA1001_2
//
//  Created by Martin on 12/11/18.
//  Copyright © 2018年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SABDeviceInfo : NSObject
@property (nonatomic, copy) NSString *deviceID;//设备ID
@property (nonatomic, assign) NSString *firmwareVersion;//固件版本
@end

NS_ASSUME_NONNULL_END
