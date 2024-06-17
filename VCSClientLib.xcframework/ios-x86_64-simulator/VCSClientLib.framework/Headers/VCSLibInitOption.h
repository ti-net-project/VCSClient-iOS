//
//  VCSOptions.h
//  VCSClientLib
//
//  Created by houli on 2024/4/24.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface VCSLibInitOption : NSObject
/**
 *  客服REST服务器地址,默认:https://kefu.easemob.com ,没有设置的情况下都使用默认地址
 *  只能在[VCSClient initializeSDKWithOptions:]中设置，不能在程序运行过程中动态修改
 */
@property (nonatomic,copy) NSString *kefuRestServer;
/*!
 *  \~chinese
 *  插件配置id
 *
 *  \~english
 *  tenantId
 */
@property (nonatomic,copy) NSString *configId;
/*!
 *  \~chinese
 *  控制台是否输出log, 默认为NO
 *
 *  \~english
 *  Whether print log to console, default is NO
 */
@property (nonatomic, assign) BOOL enableConsoleLog;

/*!
 *  \~chinese
 *   是否开启观测云, 默认为YES
 */
@property (nonatomic, assign) BOOL enableFTMobileSDK;
@end

NS_ASSUME_NONNULL_END
