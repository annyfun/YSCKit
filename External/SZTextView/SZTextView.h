//
//  SZTextView.h
//  SZTextView
//
//  Created by glaszig on 14.03.13.
//  Copyright (c) 2013 glaszig. All rights reserved.
//  FORMATED!
//

#import <UIKit/UIKit.h>

@interface SZTextView : UITextView

@property (copy, nonatomic) NSString *placeholder;
@property (retain, nonatomic) UIColor *placeholderTextColor UI_APPEARANCE_SELECTOR;
@property (assign, nonatomic) NSInteger maxLength;      //default is -1 (means no limit)

@end
