//
//  HDAppID.h
//  HelpDeskLite
//
//  Created by houli on 2022/1/6.
//  Copyright © 2022 hyphenate. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, HDCMDMessageCallType) {
    HDCMDMessageCallType_VisitorInitiates_AgentAnswer    = 0,    /**  访客发起座席应答  */
    HDCMDMessageCallType_Agent_SendVisitorCallback,              /**座席主动回呼确认访客是否有回应  */
    HDCMDMessageCallType_Agent_Cancel_CallBack,                  /**座席取消回呼  */
    HDCMDMessageCallType_Agent_SendVisitorCallback_Ticket        /**座席主动回呼 携带加入房间的参数  */
};


@interface HDKeyCenter : NSObject

/**
  声网 appid 访客端通过消息传过来
 */
@property (nonatomic, strong)  NSString * agoraAppid;

/**
 声网token 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * agoraToken;
/**
 声网channel 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * agoraChannel;
/**
 声网uid 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * agoraUid;
/**
 callid 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * callid;
/**
 屏幕分享id
 */
@property (nonatomic, strong) NSString * shareUid;
/**
 座席昵称
 */
@property (nonatomic, strong) NSString * agentNickName;
/**
 座席昵称
 */
@property (nonatomic, strong) NSString * agentUid;
/**
 访客昵称
 */
@property (nonatomic, strong) NSString * visitorNickName;
/**
  邀请座席昵称
 */
@property (nonatomic, strong) NSString *  invitationAgentNickName;

/**
  收到座席下发的消息 解析的值 后边访客给座席发消息要用到这个值
 */
@property (nonatomic, strong) NSString *  rtmChannel;
/**
    新增字段 视频接通 收到cmd消息类型
 */
//@property (nonatomic, assign) HDCMDMessageCallType  callType ;

/**
 //当前通话设置的清晰度
//      1: '480p_1' 标清,
//      2: '720p_1' 高清,
//      3: '1080p_1 超高清'
 */
@property (nonatomic, assign) NSInteger  clarityType ;

//座席相关信息
@property (nonatomic, strong) NSDictionary *  agentTicket;
//共享相关信息
@property (nonatomic, strong) NSDictionary *  shareScreenTicket;

@end


