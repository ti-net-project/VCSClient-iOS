//
//  VCSRtmLoginGate.h
//  VCSClientLib
//
//  RTM 一次登录与链路提示的纯决策。入参是声网 AgoraRtmLinkState / AgoraRtmLinkStateChangeReason 的整型值。
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, VCSRtmLoginStep) {
    VCSRtmLoginStepWait = 0,
    VCSRtmLoginStepSubscribe,
    VCSRtmLoginStepFailPendingLogin,
    VCSRtmLoginStepDisplace,
    VCSRtmLoginStepLinkOnly,
};

@interface VCSRtmLoginDecision : NSObject
@property (nonatomic, assign) VCSRtmLoginStep step;
@property (nonatomic, assign) BOOL showSameUidPrompt;
@end

VCSRtmLoginDecision *VCSRtmLoginDecide(BOOL loginCompleted, NSInteger linkState, NSInteger reasonCode);

typedef NS_ENUM(NSInteger, VCSRtmReconnectPromptMode) {
    VCSRtmReconnectPromptModeNone = 0,
    VCSRtmReconnectPromptModeEvery6Seconds,
    VCSRtmReconnectPromptModeEvery30Seconds,
    VCSRtmReconnectPromptModeStop,
};

@interface VCSRtmLinkUxDecision : NSObject
@property (nonatomic, assign) BOOL showConnectedSuccess;
@property (nonatomic, assign) VCSRtmReconnectPromptMode reconnectPromptMode;
@property (nonatomic, assign) BOOL showSameUidPrompt;
@property (nonatomic, assign) BOOL showDeviceFailed;
@end

VCSRtmLinkUxDecision *VCSRtmLinkUxDecide(NSInteger previousState, NSInteger currentState, NSInteger reasonCode);

typedef NS_ENUM(NSInteger, VCSLinkLoginAction) {
    VCSLinkLoginActionRejectBusy = 0,
    VCSLinkLoginActionAlreadyLoggedIn,
    VCSLinkLoginActionLogoutThenLogin,
    VCSLinkLoginActionLogin,
};

/// 打开链接后的 login：正在登录拒绝；已有连接且换访客或换插件先退出；同访客直接成功。
VCSLinkLoginAction VCSLinkLoginDecide(BOOL loggingIn, BOOL loggedIn, BOOL hasClient, BOOL sameVisitor, BOOL pluginReset);

NS_ASSUME_NONNULL_END
