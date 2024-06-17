//
//  VCSClientCallKit.h
//  VCSClientKit
//
//  Created by houli on 2024/5/15.
//

#import <Foundation/Foundation.h>
#import <VCSClientKit/VCSCallModel.h>
#import <VCSClientKit/VCSKitInitOption.h>
NS_ASSUME_NONNULL_BEGIN

@interface VCSClientCallKit : NSObject

+ (instancetype)shareCallKit;

/*!
 *  初始化sdk kit
 */
- (void)initWithOption:(VCSKitInitOption *)option;
/**
 *  登录
 * 用户 App 的 userID（为空的情况下，系统默认为 UUID ，不可包含中文或特殊符号，建议使用用户系统 ID 方便 APP 拓展功能）
 */
- (void)loginWithVisitorId:(NSString *_Nonnull)visitorId Success:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/**
 *  退出登录
 */
- (void)logout:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/**
 * 发起视频邀请
 */
- (void)videoCall:(VCSCallModel *_Nonnull)model Success:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/**
 * sdk 版本号
 */
+ (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
