//
//  VCSClientKitConfig.h
//  VCSClientKit
//
//  Created by easemob on 2024/5/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// 内部保存的配置信息
@interface VCSScreenShareConfig : NSObject
//屏幕共享的ExtensionBundleId
@property (nonatomic, strong) NSString * screenShareExtensionBundleId;
//屏幕共享通信是通过appGroup通信appGroupName 就是在开发者账号上创建的appGroup的名字
@property (nonatomic, strong) NSString * appGroupName;
@end
@interface VCSClientKitConfig : NSObject
/**
 *  客服REST服务器地址,默认:https://kefu.easemob.com ,没有设置的情况下都使用默认地址
 *  只能在[VCSClient initializeSDKWithOptions:]中设置，不能在程序运行过程中动态修改
 */
@property (nonatomic,copy) NSString *kefuRestServer;
/*!
 *  \~chinese
 *  插件配置id
 */
@property (nonatomic,copy) NSString *configId;
/*!
 *  \~chinese
 *  控制台是否输出log, 默认为NO
 */
@property (nonatomic, assign) BOOL enableConsoleLog;

/*!
 *  \~chinese
 *   需要屏幕共享时 要配置这个参数
 */
@property (nonatomic, strong) VCSScreenShareConfig * shareConfig;
@end

NS_ASSUME_NONNULL_END
