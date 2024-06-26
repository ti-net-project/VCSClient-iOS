//
//  VCSClient.h
//  VCSClientLib
//
//  Created by houli on 2024/4/24.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSError.h>
#import <VCSClientLib/VCSLibInitOption.h>
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
- (VCSError *)initializeSDKWithOptions:(VCSLibInitOption *)aOptions;

+ (NSString *)sdkVersion;
+ (NSString *)rtmSdkVersion;
- (NSString *)kefuRestServer;

/// 添加
/// - Parameters:
///   - content: 日志内容
///   - property: 自定义属性(可选)
-(void)vcslogInfo:(NSString *)content property:(NSDictionary *)property;

/// 创建页面
///
/// 在 `-startViewWithName` 方法前调用，该方法用于记录页面的加载时间，如果无法获得加载时间该方法可以不调用。
/// - Parameters:
///  - viewName: 页面名称
///  - loadTime: 页面加载时间（纳秒级）
-(void)vcsOnCreateView:(NSString *)viewName loadTime:(NSNumber *)loadTime;

/// 进入页面
/// - Parameters:
///  - viewName: 页面名称
///  - property: 事件自定义属性(可选)
-(void)vcsStartViewWithName:(NSString *)viewName property:(nullable NSDictionary *)property;

/// 离开页面
/// - Parameter property: 事件自定义属性(可选)
-(void)vcsStopViewWithProperty:(nullable NSDictionary *)property;


@end

NS_ASSUME_NONNULL_END
