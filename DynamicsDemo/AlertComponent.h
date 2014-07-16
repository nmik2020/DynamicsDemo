//
//  AlertComponent.h
//  DynamicsDemo
//
//  Created by Nidal Ilyas on 7/17/14.
//  Copyright (c) 2014 Vivacious. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface AlertComponent : NSObject

@property (nonatomic, strong) UIView *alertView;
@property (nonatomic, strong) UIView *backgroundView;
@property (nonatomic, strong) UIView *targetView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *messageLabel;
@property (nonatomic, strong) UIDynamicAnimator *animator;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSArray *buttonTitles;
@property (nonatomic) CGRect initialAlertViewFrame;
@property (nonatomic, strong) void(^selectionHandler)(NSInteger, NSString *);

- (id)initAlertWithTitle:(NSString *)title andMessage:(NSString *)message andButtonTitles:(NSArray *)buttonTitles andTargetView:(UIView *)targetView;
- (void)setupBackgroundView;
- (void)setupAlertView;
- (void)handleButtonTap:(UIButton *)sender;
- (void)showAlertViewWithSelectionHandler:(void(^)(NSInteger buttonIndex, NSString *buttonTitle))handler;
@end
