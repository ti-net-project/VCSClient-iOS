//
//  VCSCommonUtils.h
//  VCSClientLib
//
//  Created by houli on 2024/6/14.
//
#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSMessage.h>
NS_ASSUME_NONNULL_BEGIN

@interface VCSCommonUtils : NSObject

// NSString的URL编码
+(NSString *)URLEncodeWithString:(NSString *)unEncodeString;

// uuid生成
+ (NSString *)uuidString;

// 字典转字符串
+ (NSString*)toNSStringWithDictionary:(NSDictionary *)dict;

// 字符串转字典
+ (NSDictionary *)toDictionaryWithNSString:(NSString *)string;

/// 判断字符传
+ (BOOL)isEmptyString:(NSString *)string;

/// 判断字典是否包含某个key
+ (BOOL)dictionary:(id)dict containsKey:(NSString *)key;

/// 校验预约或一键邀请链接。通过时返回 nil。
+ (nullable NSString *)subscribeLinkError:(nullable NSDictionary *)linkParams;

/// 校验预约链接 query。通过时返回 nil，并留给下一次访客邀请补进预约字段。
+ (nullable NSString *)acceptSubscribeLink:(nullable NSDictionary *)linkParams;

/// 登录或发起通话失败时丢掉已接收的预约链接参数。
+ (void)clearSubscribeLink;

/// 取出并清除已接收的预约链接参数。
+ (nullable NSDictionary *)consumeSubscribeLink;

/// 组装整体消息格式 发送接口使用
/// - Parameters:
///   - srcChannel: srcChannel description
///   - messagetype: messagetype description
///   - content: content description
+ (NSDictionary *)vcsFormatMessageData:(NSString *)srcChannel withVisitorName:(NSString *)visistorName withMessage:(VCSMessage *)message;

/// 组装vcsRtmMessage 格式 发送RTM 消息用 （已废弃）
/// - Parameters:
///   - srcChannel: srcChannel description
///   - bodies: bodies description
//+ (NSDictionary *)vcsRtmMessageChannel:(NSString *)srcChannel withMessage:(VCSMessage *)message;

/// 组装vcsRtmMessage 格式 发送RTM 消息用。
/// + (NSDictionary *)vcsRtmMessageChannel:(NSString *)srcChannel withMessage:(VCSMessage *)message
+ (NSDictionary *)vcsRtmMessage:(VCSMessage *)message;

///  保存visitorId 到本地
+ (void)vcsSaveVisitorId:(NSString *)visitorId;
+ (NSString *)visitorId;
+ (void)removeVisitorId;




@end

NS_ASSUME_NONNULL_END
