//
//  HDVECGuidanceModel.h
//  CustomerSystem-ios
//
//  Created by easemob on 2023/4/11.
//  Copyright © 2023 easemob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSClientLib.h>
typedef NS_ENUM(NSInteger, HDCallVideoInputType){
    HDCallVideoInputDefault=100,   // 默认入口 正常视频邀请界面
    HDCallVideoInputGuidance //   询前引导 入口
};
NS_ASSUME_NONNULL_BEGIN

@interface HDCallInputModel : NSObject
@property (nonatomic, strong) NSString *appkey;
@property (nonatomic, assign) HDCallVideoInputType videoInputType;
@property (nonatomic, strong) NSString *vec_imServiceNum;
@property (nonatomic, strong) NSString *vec_cecSessionId; // cec的会话id  会话跳转到 vec 使用
@property (nonatomic, strong) NSString *vec_cecVisitorId; // cec的访客id  会话跳转到 vec 使用

@property (nonatomic, strong) NSString *cec_imServiceNum; // 会话的im服务号
@property (nonatomic, assign) NSInteger queueId; //  vec 的技能组id 如果有转技能组使用到了这个值  后台对这个值有强校验 必须是数字类型才能正常发起视频
@property (nonatomic, strong) NSString * menuid; //  vec 的菜单id
@property (nonatomic, strong) NSString *queueType; //  vec queueType

//界面相关配置
/**
 *    VEC 视频 页面 场景
 *     1、发起页面。
 *     2、二次确认界面
 *     3、排队界面
 *     4、视频通话界面
 *     5、满意度界面
 */

//设置是否不需要排队界面
@property (assign, nonatomic) BOOL  isNotWaitView;
//设置是否不需要满意度界面
@property (assign, nonatomic) BOOL  isNotEnquiryInvite;



// vcs 相关使用参数
//新增字段 有需要收到通知参数的可以通过这个字段传递
@property (strong, nonatomic) HDKeyCenter * keyCenter;
//访客信息
@property (nonatomic, strong) VCSVisitorInfo *visitorInfo;
//访客id 如果不传默认sdk会生成一个
@property (nonatomic, strong) NSString *visitorUid;
//插件id
@property (nonatomic, strong) NSString *vec_configid;
//业务标识
@property (nonatomic, strong) NSDictionary *serviceIdentification;
//访客vip 标签
@property (nonatomic, strong) NSDictionary *vipTags;
//扩展字段
@property (nonatomic, strong) NSDictionary *parameters;
//透传消息内容
@property (nonatomic, strong) NSString *text;
@end

NS_ASSUME_NONNULL_END
