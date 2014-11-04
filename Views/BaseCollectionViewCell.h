//
//  BaseCollectionViewCell.h
//  KQ
//
//  Created by yangshengchao on 14-11-4.
//  Copyright (c) 2014年 yangshengchao. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseCollectionViewCell : UICollectionViewCell

+ (CGSize)SizeOfCell;
- (void)layoutDataModel:(BaseDataModel *)dataModel;
- (void)layoutDataModels:(NSArray *)dataModelArray;

@end
