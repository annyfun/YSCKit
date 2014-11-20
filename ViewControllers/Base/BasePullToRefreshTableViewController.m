//
//  BasePullToRefreshTableViewController.m
//  TGO2
//
//  Created by  YangShengchao on 14-4-18.
//  Copyright (c) 2014年 SCSD_TGO_TEAM. All rights reserved.
//

#import "BasePullToRefreshTableViewController.h"

@interface BasePullToRefreshTableViewController ()

@end

@implementation BasePullToRefreshTableViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    if ([NSString isNotEmpty:[self nibNameOfCell]]) {
        [self.tableView registerNib:[UINib nibWithNibName:[self nibNameOfCell] bundle:nil] forCellReuseIdentifier:kCellIdentifier];
    }
    self.tableView.tableHeaderView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 0.01)];
    self.tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 0.01)];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    self.tableView.backgroundColor = kDefaultViewColor;
}

#pragma mark - 私有方法子类无需重写

- (void)reloadByAdding:(NSArray *)anArray {
    [super reloadByAdding:anArray];
    NSInteger displayedSectionIndex = [self.dataArray count];
    NSMutableArray *insertedIndexPaths = [NSMutableArray array];
    for (NSUInteger insertedIndex = 0, insertedCount = [anArray count]; insertedIndex < insertedCount; insertedIndex ++) {
        [insertedIndexPaths addObject:[NSIndexPath indexPathForRow:displayedSectionIndex + insertedIndex inSection:0]];
    }
    NSIndexSet *insertedIndexSet = [NSIndexSet indexSetWithIndexesInRange:NSMakeRange(displayedSectionIndex, [anArray count])];
    [self.tableView beginUpdates];
    [self.dataArray insertObjects:anArray atIndexes:insertedIndexSet];
    [self.tableView insertRowsAtIndexPaths:insertedIndexPaths withRowAnimation:UITableViewRowAnimationAutomatic];
    [self.tableView endUpdates];
}

- (UIScrollView *)contentScrollView {
    return self.tableView;
}

- (void)reloadData {
    [self.tableView reloadData];
}

#pragma mark - 子类必须重写的方法

- (UIView *)layoutCellWithData:(id)object atIndexPath:(NSIndexPath *)indexPath {
	BaseTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:kCellIdentifier];
    if ([cell isKindOfClass:[BaseTableViewCell class]]) {
        [(BaseTableViewCell *)cell layoutDataModel:object];//简单设置cell显示内容，如果需要处理cell的特殊点击事件就必须重写该方法
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
	return cell;
}

#pragma mark - UITableView特有的方法

- (CGFloat)tableViewCellHeightForData:(id)object atIndexPath:(NSIndexPath *)indexPath {
    NSString *nibName = [self nibNameOfCell];
    if ([NSString isNotEmpty:nibName] &&
        [NSClassFromString(nibName) isSubclassOfClass:[BaseTableViewCell class]]) {
        return [NSClassFromString(nibName) HeightOfCell];
    }
    else {
        return 44.0f;
    }
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self cellCount];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    id objectModel = nil;
    if (indexPath.row < [self.dataArray count]) {
        objectModel = [self.dataArray objectAtIndex:indexPath.row];
    }
    UITableViewCell *cell = (UITableViewCell *)[self layoutCellWithData:objectModel atIndexPath:indexPath];
    return cell;
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    id objectModel = nil;
    if (indexPath.row < [self.dataArray count]) {
        objectModel = [self.dataArray objectAtIndex:indexPath.row];
    }
    CGFloat rowHeight = [self tableViewCellHeightForData:objectModel atIndexPath:indexPath];
    return rowHeight;
}

- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath {
    return YES;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    id objectModel = nil;
    if (indexPath.row < [self.dataArray count]) {
        objectModel = [self.dataArray objectAtIndex:indexPath.row];
    }
    [self clickedCell:objectModel atIndexPath:indexPath];
}

@end
