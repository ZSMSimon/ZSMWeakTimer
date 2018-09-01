//
//  ZSMWeakTimer.h
//  ZSMWeakTimer
//
//  Created by acadsoc on 2018/9/1.
//  Copyright © 2018年 Simon. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ZSMWeakTimer.
FOUNDATION_EXPORT double ZSMWeakTimerVersionNumber;

//! Project version string for ZSMWeakTimer.
FOUNDATION_EXPORT const unsigned char ZSMWeakTimerVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ZSMWeakTimer/PublicHeader.h>

@interface ZSMWeakTimer : NSObject

/**
 创建一个指定参数和时间的计时器，并返回线程安全的计时器对象。

 @param timeInterval 倒计时
 @param target 执行的任务对象
 @param selector 执行的任务方法
 @param userInfo 一般传Nil
 @param repeats 是否重复执行（NO：只执行一次 YES：重复执行，直到调用invalidate销毁）
 @param dispatchQueue 返回任务的队列（串行或并行）
 @return 计时器对象
 */
- (instancetype)initWithTimeInterval:(NSTimeInterval)timeInterval
                              target:(id)target
                            selector:(SEL)selector
                            userInfo:(id)userInfo
                             repeats:(BOOL)repeats
                       dispatchQueue:(dispatch_queue_t)dispatchQueue;

/**
 同上功能的类方法
 */
+ (instancetype)scheduledTimerWithTimeInterval:(NSTimeInterval)timeInterval
                                        target:(id)target
                                      selector:(SEL)selector
                                      userInfo:(id)userInfo
                                       repeats:(BOOL)repeats
                                 dispatchQueue:(dispatch_queue_t)dispatchQueue;

/**
 启动未安排进程的计时器
 @warning 已在进程中工作的计时器调用这个方法，会导致未知问题
 */
- (void)schedule;


/**
 给定触发计时器的时间间隔偏差
 */
@property (atomic, assign) NSTimeInterval tolerance;

/**
 使计时器在调用这个方法的队列上手动同步触发（简称+1s操作）
 */
- (void)fire;

/**
 可以阻止如何队列上的计时器运行
 放在dealloc中就好，因为它不会有delegate的对象持有，尽情的释放吧！
 */
- (void)invalidate;


/**
 nil
 */
- (id)userInfo;

@end

