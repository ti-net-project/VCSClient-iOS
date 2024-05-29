//
//  VCSClientCallKit.h
//  VCSClientKit
//
//  Created by easemob on 2024/5/15.
//

#import <Foundation/Foundation.h>
#import <VCSClientKit/HDCallInputModel.h>
#import <VCSClientKit/VCSClientKitConfig.h>
NS_ASSUME_NONNULL_BEGIN

@interface VCSClientCallKit : NSObject

+ (instancetype)shareCallKit;

/*!
 *  初始化sdk kit
 */
- (HDError *)initializeKitConfig:(VCSClientKitConfig *)config;

/**
 * 发起视频邀请
 */
- (void)vcsCreteVideoInvite:(HDCallInputModel *_Nonnull)model Completion:(void(^)(id  responseObject, HDError *error))aCompletion;

/**
 * 设置收到视频邀请事件监听
 * 用户 App 的 userID（为空的情况下，系统默认为 UUID ，不可包含中文或特殊符号，建议使用用户系统 ID 方便 APP 拓展功能）
 */
- (void)vcsVideoCallEventListenerWithVisitorId:(NSString*)visitorId Success:(void (^)(void))successBlock withError:(void (^)(HDError *error))errorBlock;

/**
 * 取消 收到视频邀请事件监听
 */
- (void)vcsVideoCallEventListenerCancelSuccess:(void (^)(void))successBlock withError:(void (^)(HDError *error))errorBlock;

@end

NS_ASSUME_NONNULL_END
