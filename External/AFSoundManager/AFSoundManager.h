//
//  AFSoundManager.h
//  AFSoundManager-Demo
//
//  Created by Alvaro Franco on 4/16/14.
//  Copyright (c) 2014 AlvaroFranco. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <objc/runtime.h>

#import "AFAudioRouter.h"

typedef NS_ENUM(NSInteger, AudioPlayStatus) {
    AudioPlayStatusReadyToPlay = 0,
    AudioPlayStatusPlaying,
    AudioPlayStatusPause,
    AudioPlayStatusPlayError
};

typedef void (^progressBlock)(CGFloat totalTime, CGFloat elapsedTime, NSError *error);


@interface AFSoundManager : NSObject

+(instancetype)sharedManager;

@property (nonatomic, strong) AVAudioPlayer *audioPlayer;
@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, strong) AVAudioRecorder *recorder;
@property (nonatomic, strong) UISlider* volumeViewSlider;
@property (nonatomic, assign) CGFloat currentVolume;        //监控该参数更新UI界面

@property (nonatomic, copy) BookModel *currentPlayingBook;  //当前播放的书籍
@property (nonatomic, assign) NSInteger audioPlayIndex;     //当前播放的下标
@property (nonatomic, assign) CGFloat audioPlayProgress;    //当前播放的进度百分比
@property (nonatomic, assign) CGFloat audioTotalTime;       //音频总时长(s)
@property (nonatomic, assign) CGFloat audioElapsedTime;     //已经播放的时长(s)
@property (nonatomic, assign) AudioPlayStatus audioPlayStatus;          //当前的音频的播放状态

-(void)startPlayingLocalFileWithPath:(NSString *)name withBlock:(progressBlock)block;
-(void)startStreamingRemoteAudioFromURL:(NSString *)url withBlock:(progressBlock)block;

-(void)startPlayingBook:(BookModel *)bookModel withIndex:(NSInteger)audioIndex;
-(void)playAudioAtIndex:(NSInteger)playIndex;
-(ChapterModel *)currentPlayingChapter;
- (CGFloat)getCurrentVolume;//获得初始化音量必须调用该方法

-(void)pause;
-(void)resume;
-(void)stop;
-(void)restart;
-(void)reset;

-(void)playNextAudio;
-(void)playPreviousAudio;

-(void)changeVolumeToValue:(CGFloat)volume;
-(void)changeSpeedToRate:(CGFloat)rate;
-(void)moveToSecond:(int)second;
-(void)moveToSection:(CGFloat)section;

-(void)startRecordingAudioWithFileName:(NSString *)name andExtension:(NSString *)extension shouldStopAtSecond:(NSTimeInterval)second;
-(void)pauseRecording;
-(void)resumeRecording;
-(void)stopAndSaveRecording;
-(void)deleteRecording;
-(NSInteger)timeRecorded;

-(BOOL)areHeadphonesConnected;
-(void)forceOutputToDefaultDevice;
-(void)forceOutputToBuiltInSpeakers;

@end


@interface NSTimer (Blocks)

+(id)scheduledTimerWithTimeInterval:(NSTimeInterval)inTimeInterval block:(void (^)())inBlock repeats:(BOOL)inRepeats;
+(id)timerWithTimeInterval:(NSTimeInterval)inTimeInterval block:(void (^)())inBlock repeats:(BOOL)inRepeats;

@end

@interface NSTimer (Control)

-(void)pauseTimer;
-(void)resumeTimer;

@end
