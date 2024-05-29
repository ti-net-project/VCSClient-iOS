//
//  VCSClient.h
//  VCSClientLib
//
//  Created by easemob on 2024/4/24.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/HDError.h>
#import <VCSClientLib/VCSOptions.h>
#import <VCSClientLib/VCSClientDelegate.h>
#import <VCSClientLib/VCSMessage.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCSClient : NSObject
/*!
 *  \~chinese
 *  获取SDK实例
 *
 *  \~english
 *  Get SDK single instance
 */
+ (instancetype)sharedClient;

/*!
 *  \~chinese
 *  初始化sdk
 *  @param aOptions  SDK配置项
 *  @result 错误信息
 */
- (HDError *)initializeSDKWithOptions:(VCSOptions *)aOptions;

+ (NSString *)sdkVersion;
+ (NSString *)rtmSdkVersion;
- (NSString *)kefuRestServer;


@end

NS_ASSUME_NONNULL_END
