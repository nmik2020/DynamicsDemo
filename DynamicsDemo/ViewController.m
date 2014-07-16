//
//  ViewController.m
//  DynamicsDemo
//
//  Created by Nidal Ilyas on 7/16/14.
//  Copyright (c) 2014 Vivacious. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
            

@end

@implementation ViewController
            
- (void)viewDidLoad {
    [super viewDidLoad];
    self.alertComponent = [[AlertComponent alloc] initAlertWithTitle:@"Custom Alert"
                                                          andMessage:@"You have a new e-mail message, but I don't know from whom."
                                                     andButtonTitles:@[@"Show me", @"I don't care", @"For me, really?"]
                                                       andTargetView:self.view];
    UISwipeGestureRecognizer *showMenuGesture = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(showMenu:)];
    
    showMenuGesture.direction = UISwipeGestureRecognizerDirectionLeft;
    
    [self.view addGestureRecognizer:showMenuGesture];
    CGRect desiredMenuFrame = CGRectMake(0.0, 20.0, 150.0, self.view.frame.size.height);
    self.menuComponent = [[MenuComponent alloc] initMenuWithFrame:desiredMenuFrame
                                                       targetView:self.view
                                                        direction:menuDirectionRightToLeft
                                                          options:@[@"Download", @"Upload", @"E-mail", @"Settings", @"About"]
                                                     optionImages:@[@"download", @"upload", @"email", @"settings", @"info"]];
//    [self setupOptionsTableView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)showMenu:(UIGestureRecognizer *)gestureRecognizer {
    [self.menuComponent showMenuWithSelectionHandler:^(NSInteger selectedOptionIndex) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"UIKit Dynamics Menu"
                                                        message:[NSString stringWithFormat:@"You selected option #%d", selectedOptionIndex + 1]
                                                       delegate:nil
                                              cancelButtonTitle:nil
                                              otherButtonTitles:@"Okay", nil];
        [alert show];
    }];
}

- (IBAction)showAlertView:(id)sender {
    [self.alertComponent showAlertViewWithSelectionHandler:^(NSInteger buttonIndex, NSString *buttonTitle) {
        NSLog(@"%ld, %@", (long)buttonIndex, buttonTitle);
    }];
}
@end
