//
//  VCSCallLibEventDelegate.h
//  VCSClientLib
//
//  Created by easemob on 2024/5/13.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSMessage.h>
#import <VCSClientLib/VCSKeyCenter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VCSCallLibEventDelegate <NSObject>

@optional

//收到消息的回调
- (void)messagesDidReceive:(VCSMessage *)aMessages;

/*!
 *  \~chinese
 *  收到VEC 创建视频会话的事件 只有访客主动发起的时候才会通知
 *  @param parameter   视频会话创建的参数
 */
- (void)onTicketDidReceiveRtcSessionCreateEvent:(NSDictionary *)parameter;

/*!
 *  \~chinese
 *  接收到访客主动发起的视频请求
 *  @param keyCenter   创建视频请求必要的参数
 */
- (void)onCallReceivedVisitorParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  接收到座席主动发起的视频请求
 *  @param keyCenter   创建视频请求必要的参数
 */
- (void)onCallReceivedAgentParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  座席回呼 主动发起的视频请求 确认事件
 */
- (void)onCallReceivedAgentSureParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  座席回呼  取消回呼
 */
- (void)onCallReceivedAgentCancelCallBackParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  通话中 座席主动挂断
 */
- (void)onCallReceivedAgentHangUpMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *    通话中异常参数
 */
- (void)onCallReceivedExceptionMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *    第三方座席进来 获取对应的座席信息
 *  @param thirdAgentNickName   座席昵称
 *
 *  \~english
 *  Receiving a Video request
 *
 */
- (void)onCallReceivedInvitation:(NSString *)thirdAgentNickName withUid:(NSString *)uid withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *     vec 独立访客端 收到 座席拒绝的通知
 *
 */
- (void)onCallHangUpInvitationWithMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *     vec 独立访客端 收到 座席信息推送
 *
 */
- (void)onCallLinkMessagePush:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *     vec 独立访客端 收到 ocr 识别
 *
 */
- (void)onCallLOcrIdentify:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *     vec 独立访客端 收到 身份认证
 *
 */
- (void)onCallFaceIdentify:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *     vec 独立访客端 收到 数字签名
 *
 */
- (void)onCallSignIdentify:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *   收到满意度
 */
- (void)onEnquiryInviteParameter:(NSDictionary *)enquiryInvite withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *   麦克风 通知
 */
- (void)onMuteLocalAudioStreamParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *   摄像头
 */
- (void)onMuteLocalVideoStreamParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *   切换摄像头
 */
- (void)onSwitchCameraParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *   对焦、
 */
- (void)onFocusingOnParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *  开关闪光灯
 */
- (void)onCameraTorchOnParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *    flashlight
 *    手电筒
 */
- (void)onFlashlightParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;


/*!
 *  \~chinese
 *    vecNewChatMsg
 *    视频通话中有新消息进来的cmd通知
 */
- (void)onVecNewChatCMDMsgWithMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *    vecNewChatMsg
 *    视频排队 超时 接收到的cmd 通知
 */
- (void)onVECWaitTimeoutCloseKefuRtcWaitCallMsgWithMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *       视频通话中 收到消息的通知
 *  @param aMessages  消息列表<VCSMessage>
 *
 *  \~english
 *  Delegate method will be invoked when receiving new messages
 *
 *  @param aMessages  Receivecd message list<VCSMessage>
 */
- (void)on_VecMessagesDidReceive:(NSArray *)aMessages;


/**
 * 引擎全局内错误信息事件回调
 *
 * @param errorCode         错误码
 * @param errorMessage   错误描述
 */
- (void)onError:(HDErrorCode)errorCode errorMessage:(nonnull NSString *)errorMessage;
@end

NS_ASSUME_NONNULL_END
