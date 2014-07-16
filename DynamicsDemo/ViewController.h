//
//  ViewController.h
//  DynamicsDemo
//
//  Created by Nidal Ilyas on 7/16/14.
//  Copyright (c) 2014 Vivacious. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MenuComponent.h"
#import "AlertComponent.h"
@interface ViewController : UIViewController

@property (nonatomic, strong) MenuComponent *menuComponent;
@property (nonatomic, strong) AlertComponent *alertComponent;

- (void)showMenu:(UIGestureRecognizer *)gestureRecognizer;

@end

