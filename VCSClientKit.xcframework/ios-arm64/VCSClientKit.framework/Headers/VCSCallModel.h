//
//  VCSCallModel.h
//  VCSClientKit
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSClientLib.h>
NS_ASSUME_NONNULL_BEGIN

/// 呼叫操作的数据Model类
@interface VCSCallModel : NSObject

/// 访客id 必传字段
@property (nonatomic, strong) NSString *visitorId;

/// 预约码。trim 后为空则不写入 messageData
@property (nonatomic, copy, nullable) NSString *subscribeCode;

/// 进线来源。预约为 2。nil 则不写入 messageData
@property (nonatomic, strong, nullable) NSNumber *source;

/// 领取后的座席工号
@property (nonatomic, copy, nullable) NSString *cno;

/// 手机号
@property (nonatomic, copy, nullable) NSString *tel;

/// 访客姓名。不做百分号编码
@property (nonatomic, copy, nullable) NSString *visitorName;

/// 访客信息Model
@property (nonatomic, strong) VCSVisitorInfo *visitorInfo;

/// 业务标识
@property (nonatomic, strong) NSDictionary *serviceIdentification;

/// 访客vip 标签
@property (nonatomic, strong) NSDictionary *vipTags;

/// 扩展字段
@property (nonatomic, strong) NSDictionary *parameters;

/// 透传消息内容
@property (nonatomic, strong) NSString *text;

@end

NS_ASSUME_NONNULL_END
