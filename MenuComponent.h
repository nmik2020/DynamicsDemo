
//  MenuComponent.h
//  DynamicsDemo
//
//  Created by Nidal Ilyas on 7/16/14.
//  Copyright (c) 2014 Vivacious. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum MenuDirectionOptionTypes{
    menuDirectionLeftToRight,
    menuDirectionRightToLeft
} MenuDirectionOptions;

@interface MenuComponent : NSObject <UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, strong) UIView *menuView;
@property (nonatomic, strong) UIView *backgroundView;
@property (nonatomic, strong) UIView *targetView;
@property (nonatomic, strong) UITableView *optionsTableView;
@property (nonatomic, strong) NSArray *menuOptions;
@property (nonatomic, strong) NSArray *menuOptionImages;
@property (nonatomic, strong) UIDynamicAnimator *animator;
@property (nonatomic) MenuDirectionOptions menuDirection;
@property (nonatomic) CGRect menuFrame;
@property (nonatomic) CGRect menuInitialFrame;
@property (nonatomic) BOOL isMenuShown;
@property (nonatomic, strong) void(^selectionHandler)(NSInteger);


@property (nonatomic, strong) UIColor *menuBackgroundColor;
@property (nonatomic, strong) NSMutableDictionary *tableSettings;
@property (nonatomic) CGFloat optionCellHeight;
@property (nonatomic) CGFloat acceleration;

- (id)initMenuWithFrame:(CGRect)frame targetView:(UIView *)targetView direction:(MenuDirectionOptions)direction options:(NSArray *)options optionImages:(NSArray *)optionImages ;

- (void)setupMenuView;
- (void)setupBackgroundView;
- (void)setupOptionsTableView;
- (void)setInitialTableViewSettings;
- (void)setupSwipeGestureRecognizer;
- (void)hideMenuWithGesture:(UISwipeGestureRecognizer *)gesture;
- (void)toggleMenu;

- (void)showMenuWithSelectionHandler:(void(^)(NSInteger selectedOptionIndex))handler;

@end
