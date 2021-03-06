//
//  BaseTableViewHeaderFooterView.m
//  YSCKit
//
//  Created by yangshengchao on 14/11/20.
//  Copyright (c) 2014年 yangshengchao. All rights reserved.
//

#import "BaseTableViewHeaderFooterView.h"

@implementation BaseTableViewHeaderFooterView

- (void)awakeFromNib {
    [super awakeFromNib];
    
    [self resetFontSizeOfView];         //递归缩放label和button的字体大小
    [self resetConstraintOfView];
}

+ (CGFloat)HeightOfView {
    return AUTOLAYOUT_LENGTH(100);
}
+ (UINib *)NibNameOfView {
    return [UINib nibWithNibName:NSStringFromClass(self.class) bundle:nil];
}
- (void)layoutDataModel:(BaseDataModel *)dataModel {
    
}

- (void)layoutDataModels:(NSArray *)dataModelArray {
    
}

@end
