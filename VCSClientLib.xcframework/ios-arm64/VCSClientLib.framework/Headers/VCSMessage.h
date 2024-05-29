//
//  VCSMessage.h
//  VCSClientLib
//
//  Created by easemob on 2024/4/23.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM (NSInteger, VCSMessageType) {
    VCSMessageType_cmd    = 0,    /**  cmd*/
};
typedef NS_ENUM (NSInteger, VCSMessageEventType) {
    VCSMessageEventType_liveStreamInvitation    = 0,        /**访客主动邀请视频*/
    VCSMessageEventType_visitorCancelInvitation ,           /**访客取消邀请视频*/
    VCSMessageEventType_calling_visitorHangup ,             /**通话中访客挂断电话*/
    VCSMessageEventType_callBack_visitorAcceptInvitation ,  /**座席回呼访客接受视频邀请*/
    VCSMessageEventType_callBack_visitorRejectInvitation ,  /**座席回呼访客拒绝视频邀请*/
};
NS_ASSUME_NONNULL_BEGIN
@interface VCSVisitorInfo : NSObject
@property (nonatomic, copy) NSString* userName;
@property (nonatomic, copy) NSString* qq;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* companyName;
@property (nonatomic, copy) NSString* nickName;
@property (nonatomic, copy) NSString* phone;
@property (nonatomic, copy) NSString* desc;
@property (nonatomic, copy) NSString* email;
@property (nonatomic, copy) NSString* userDefineColumn;
@property (nonatomic, copy) NSMutableDictionary* customDic;
-(NSMutableDictionary *)content;
@end
@interface VCSMessage : NSObject

/// 消息内容
@property (nonatomic, copy) NSString *messageId;
/// form
@property (nonatomic, copy) NSString *from;
/// to
@property (nonatomic, copy) NSString *to;
/// 消息内容
@property (nonatomic, copy) NSString *text;

/// 消息事件类型
@property (nonatomic, assign) VCSMessageEventType eventMessageType;

/// 访客信息
@property (nonatomic, strong) VCSVisitorInfo *visitorInfo;

/*!
 *  \~chinese
 *  消息体
 *
 *  \~english
 *  Message body
 */
@property (nonatomic, strong) NSDictionary *body;

/*!
 *  \~chinese
 *  消息扩展
 *
 *  Key值类型必须是NSString, Value值类型必须是NSString或者 NSNumber类型的 BOOL, int, unsigned in, long long, double.
 *
 *  \~english
 *  Message extention
 *
 *  Key type must be NSString, Value type must be NSString or NSNumber of BOOL, int, unsigned in, long long, double.
 */
@property (nonatomic, copy) NSDictionary *ext;

- (void)addAttributeDictionary:(NSDictionary *)dic;
- (void)addMsgTypeDictionary:(NSDictionary *)dic;
- (void)addAttributeWithSessionExt:(NSDictionary *)dic;
- (void)addVisitorInfoContent:(NSDictionary *)dic;
@end

NS_ASSUME_NONNULL_END
