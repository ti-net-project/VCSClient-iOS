//
//  VCSCallLib.h
//  VCSClientLib
//
//  Created by houli on 2024/4/23.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSError.h>
#import <VCSClientLib/VCSMessage.h>
#import <VCSClientLib/VCSCallLibEventDelegate.h>
NS_ASSUME_NONNULL_BEGIN
// 内部保存的配置信息
@interface VCSRTCInnerRegisterModel : NSObject

//  企业id
@property(nonatomic, assign) NSInteger tenantId;
// 访客唯一标识
@property(nonatomic, copy, nullable) NSString *name;
// 声网AppId
@property(nonatomic, copy, nullable) NSString *appId;
// 声网 rtmToken
@property(nonatomic, copy, nullable) NSString *token;
// 声网 uid
@property(nonatomic, copy) NSString * uid;
// 声网 channel
@property(nonatomic, copy) NSString * channel;

@end

@interface VCSCallLib : NSObject
@property (nonatomic, strong) VCSRTCInnerRegisterModel *innerRegisterModel;
@property (nonatomic, strong) NSString *currentRtcSessionId; //创建会话的时候会赋值()
+ (instancetype)shareCallLib;

-(void)initAgoraRTMModel:(VCSRTCInnerRegisterModel*)innerRegisterModel withSuccess:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

-(void)vcsLoginRTMWithToken:(NSString *)token Success:(void (^)(void))successBlock error:(void (^)(VCSError *error))errorBlock;

//发消息
- (void)vcsSendMessage:(VCSMessage *)aMessage
         completion:(void (^)(VCSError *aError))aCompletionBlock;
//重发消息
- (void)vcsResendMessage:(VCSMessage *)aMessage completion:(void (^)( VCSError *))aCompletionBlock;
//添加回调代理
- (void)vcsAddDelegate:(id<VCSCallLibEventDelegate>_Nullable)aDelegate delegateQueue:(dispatch_queue_t _Nullable )aQueue;
//移除回调代理
- (void)vcsRemoveDelegate:(id<VCSCallLibEventDelegate>_Nullable)aDelegate;

// 获取渠道接入配置 接口地址:/api/vcs/vcs_visitor/function/setting
- (void)vcsInitSettingWithConfigId:(NSString *)configId Completion:(void (^)(id responseObject, VCSError * error))aCompletion;
//2、获取访客端初始化信息 /api/vcs/vcs_visitor/info
- (void)vcsGetVisitorInfoWithConfig:(NSString *)configId withVisitorUid:(NSString *)visitorUid WithCompletion:(void (^)(id responseObject, VCSError * error))aCompletion;
//创建视频邀请
- (void)vcsCreateVideoInviteMessage:(VCSMessage *)message withVisitorUid:(NSString *)visitorUid Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;

//结束视频会话。 未接通前 振铃放弃
- (void )vcsRingGiveUp:(VCSMessage *)message Completion:(void (^)(id responseObject, VCSError * error))aCompletion;

//排队人数 访客端
- (void)vcsGetVisitorCurrentWaitingSessionid:(NSString *)rtcSessionId withTenantId:(NSString *)tenantId Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;
//获取付费相关配置
- (void)vcsGetJgrayscaleJsonCompletion:(void (^)(id responseObject, VCSError *error))completion;

//访客挂断接口
- (void)vcsHangUpMessageTo:(NSString *)to Completion:(void (^)(VCSError *error))aCompletionBlock;

//上传sdk 版本及信息
- (void)vcsUploadSdkVersionVisitorUserName:(NSString *)visitorUserName Completion:(void (^)(id responseObject, VCSError *error))completion;
//上传用户地区信息
- (void)vcsSaveVisitorRegionWithUserName:(NSString *)username WithCompletion:(void (^)(id responseObject, VCSError *error))completion;


//退出RTM登陆
- (void)vcsLogoutCompletion:(void (^)(VCSError *error))aCompletionBlock;
#pragma mark - 座席回呼相关
//访客同意 座席主动发过来的 视频邀请
- (void)vcsVisitorAcceptInvitationMessage:(VCSMessage *)message Completion:(void (^)(VCSError * error))aCompletion;

//VISITOR_REJECT   访客拒接（振铃过程中访客主动挂断）
- (void)vcsVisitorRejectInvitationMessage:(VCSMessage *)message Completion:(void (^)(VCSError * error))aCompletion;

#pragma mark - 满意度相关
//访客提交评价
- (void)vcsSubmitVisitorEnquirySessionid:(NSString *)rtcSessionId withScore:(NSInteger)score withComment:(NSString *)comment withTagData:(NSArray *)tagData Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;


#pragma mark - 信息推送
//提交签名
- (void)vcsCommitSignData:(NSData *)data withImserviceNum:(NSString *)imServiceNum withFlowId:(NSString *)flowId Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;
//信息推送 上报接口
- (void)vcsPushBusinessReportImServiceNum:(NSString *)imServiceNum WithFlowId:(NSString *)flowId withAction:(NSString *)action  withType:(NSString *)type  withUrl:(NSString *)url withContent:(NSString *)content Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;


/*!
 *  \~chinese
 *   vec 独立访客端 远程协助 回传状态
 *
 *  @param imserviceNum   im服务号
 *  @param aContent   文本内容
 *
 */
- (VCSMessage *)vcsVisitorCallBackStateCmdMessageWithImserviceNum:(NSString *)imserviceNum withOn:(BOOL)on  withAction:(NSString *)action content:(NSString *)aContent;

/*!
 *  \~chinese
 *   vec 访客端  获取视频超时 时间
 */
- (void)vcsGetVideoLineUpTimeOutCompletion:(void (^)(id responseObject, VCSError *error))completion;
+ (NSString*)rtmSDKVersion;
@end

NS_ASSUME_NONNULL_END
