//
//  ControlLightViewController.m
//  SA1001-2-demo
//
//  Created by jie yang on 2018/11/15.
//  Copyright © 2018年 jie yang. All rights reserved.
//

#import "ControlLightViewController.h"

#import <SA1001_2/SA1001_2.h>
#import <SA1001_2/SABWorkStatus.h>

@interface ControlLightViewController ()
@property (weak, nonatomic) IBOutlet UITextField *colorRTextField;
@property (weak, nonatomic) IBOutlet UITextField *colorGTextfFiled;
@property (weak, nonatomic) IBOutlet UITextField *colorBTextFiled;
@property (weak, nonatomic) IBOutlet UITextField *colorWTextFiled;
@property (weak, nonatomic) IBOutlet UITextField *brightnessTextFiled;

@property (weak, nonatomic) IBOutlet UIButton *sendColorBtn;

@property (weak, nonatomic) IBOutlet UIButton *sendBrightnessBtn;

@property (weak, nonatomic) IBOutlet UIButton *openLightBtn;

@property (weak, nonatomic) IBOutlet UILabel *colorLabel;
@property (weak, nonatomic) IBOutlet UILabel *brightnessLabel;

@end

@implementation ControlLightViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setUI];
}

-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)setUI
{
    self.colorLabel.text = LocalizedString(@"color");
    self.brightnessLabel.text = LocalizedString(@"luminance");
    self.colorLabel.textColor = Theme.C4;
    self.brightnessLabel.textColor = Theme.C4;
    
    [self.sendColorBtn setTitle:LocalizedString(@"send") forState:UIControlStateNormal];
    [self.sendBrightnessBtn setTitle:LocalizedString(@"send") forState:UIControlStateNormal];
    [self.openLightBtn setTitle:LocalizedString(@"turn_off") forState:UIControlStateNormal];
    
    self.sendColorBtn.backgroundColor = [Theme C2];
    self.sendBrightnessBtn.backgroundColor = [Theme C2];
    self.openLightBtn.backgroundColor = [Theme C2];
    
    self.sendColorBtn.layer.masksToBounds = YES;
    self.sendColorBtn.layer.cornerRadius = 5;
    self.sendBrightnessBtn.layer.masksToBounds = YES;
    self.sendBrightnessBtn.layer.cornerRadius = 5;
    self.openLightBtn.layer.masksToBounds = YES;
    self.openLightBtn.layer.cornerRadius = 5;
}

- (IBAction)sendColorAction:(UIButton *)sender {
    
    BOOL valueR = self.colorRTextField.text.length;
    BOOL valueG = self.colorGTextfFiled.text.length;
    BOOL valueB = self.colorBTextFiled.text.length;
    BOOL valueW = self.colorWTextFiled.text.length;
    if (valueR && valueB && valueG && valueW) {
        
        int r = [self.colorRTextField.text intValue];
        int g = [self.colorGTextfFiled.text intValue];
        int b = [self.colorBTextFiled.text intValue];
        int w = [self.colorWTextFiled.text intValue];
        
        BOOL rValid = (r >= 0) && (r <= 255);
        BOOL gValid = (g >= 0) && (g <= 255);
        BOOL bValid = (b >= 0) && (b <= 255);
        BOOL wValid = (w >= 0) && (w <= 255);
        
        if (!(rValid && gValid && bValid && wValid)) {
            [Utils showMessage:LocalizedString(@"input_0_255") controller:self];
            return;
        }
        
        
        int brightness = [self.brightnessTextFiled.text intValue];
        
        if (!self.brightnessTextFiled.text.length) {
            brightness = 50;
        }
        
        BOOL brightValid = (brightness >= 0) && (brightness <= 100);
        if (!brightValid) {
            brightness = 50;
        }
        
        SLPLight *ligtht = [[SLPLight alloc] init];
        ligtht.r = r;
        ligtht.g = g;
        ligtht.b = b;
        ligtht.w = w;
        
        if (![SLPBLESharedManager blueToothIsOpen]) {
            [Utils showMessage:LocalizedString(@"phone_bluetooth_not_open") controller:self];
            return;
        }
        __weak typeof(self) weakSelf = self;
        [SLPBLESharedManager SAB:SharedDataManager.peripheral turnOnColorLight:ligtht brightness:brightness timeout:0 callback:^(SLPDataTransferStatus status, id data) {
            if (status != SLPDataTransferStatus_Succeed) {
                [Utils showDeviceOperationFailed:status atViewController:weakSelf];
            }
        }];
    }else{
        [Utils showMessage:LocalizedString(@"input_0_255") controller:self];
    }
}

- (IBAction)sendBrightnessAction:(UIButton *)sender {
    if (!self.brightnessTextFiled.text.length) {
        [Utils showMessage:LocalizedString(@"input_0_100") controller:self];
        return;
    }
    
    int brightness = [self.brightnessTextFiled.text intValue];
    BOOL brightValid = (brightness >= 0) && (brightness <= 100);
    if (!brightValid) {
        [Utils showMessage:LocalizedString(@"input_0_100") controller:self];
        return;
    }
    
    if (![SLPBLESharedManager blueToothIsOpen]) {
        [Utils showMessage:LocalizedString(@"phone_bluetooth_not_open") controller:self];
        return;
    }
    __weak typeof(self) weakSelf = self;
    [SLPBLESharedManager SAB:SharedDataManager.peripheral lightBrightness:brightness timeout:0 callback:^(SLPDataTransferStatus status, id data) {
        if (status != SLPDataTransferStatus_Succeed) {
            [Utils showDeviceOperationFailed:status atViewController:weakSelf];
        }
    }];
}



- (IBAction)openLightAction:(UIButton *)sender {
    if (![SLPBLESharedManager blueToothIsOpen]) {
        [Utils showMessage:LocalizedString(@"phone_bluetooth_not_open") controller:self];
        return;
    }
    
    __weak typeof(self) weakSelf = self;
    [SLPBLESharedManager SAB:SharedDataManager.peripheral turnOffLightTimeout:0 callback:^(SLPDataTransferStatus status, id data) {
        if (status != SLPDataTransferStatus_Succeed) {
            [Utils showDeviceOperationFailed:status atViewController:weakSelf];
        }
    }];
}
@end
