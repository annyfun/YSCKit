//
//  YSCTableViewCell.h
//  KQ
//
//  Created by yangshengchao on 14/11/17.
//  Copyright (c) 2014年 yangshengchao. All rights reserved.
//

#import "BaseTableViewCell.h"

typedef NS_ENUM(NSInteger, YSCTableViewCellStyle) {
    YSCTableViewCellStyleTitle              = 1 << 0,        //Default
    YSCTableViewCellStyleIcon               = 1 << 1,
    YSCTableViewCellStyleArrow              = 1 << 2,
    YSCTableViewCellStyleSwitch             = 1 << 3,
    YSCTableViewCellStyleSeperatorTop       = 1 << 4,
    YSCTableViewCellStyleSeperatorBottom    = 1 << 5,
    YSCTableViewCellStyleSubtitleRight      = 1 << 7,
    YSCTableViewCellStyleSubtitleLeft       = 1 << 8,
    YSCTableViewCellStyleSubtitleBottom     = 1 << 9,
};

typedef void (^StateChanged)(BOOL state);

@interface YSCTableViewCell : BaseTableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *iconImageView;
@property (weak, nonatomic) IBOutlet UILabel *seperatorTopLabel;
@property (weak, nonatomic) IBOutlet UILabel *seperatorBottomLabel;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UILabel *subtitleLabel;
@property (weak, nonatomic) IBOutlet UIImageView *arrowImageView;
@property (weak, nonatomic) IBOutlet UISwitch *stateSwitch;
@property (assign, nonatomic) YSCTableViewCellStyle style;
@property (assign, nonatomic) StateChanged stateChanged;

//icon
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *iconLeading;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *iconWidth;

//title
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *titleLeading;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *titleCenterY;

//subtitle
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *subTitleLeading;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *subTitleLeading1;      //leading to superview
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *subTitleTrailing;      //leading to titleLabel
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *subTitleCenterY;

//seperator
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *seperatorTopHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *seperatorBottomLeading;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *seperatorBottomHeight;
//others
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *switchTrailing;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *arrowTrailing;

@end
