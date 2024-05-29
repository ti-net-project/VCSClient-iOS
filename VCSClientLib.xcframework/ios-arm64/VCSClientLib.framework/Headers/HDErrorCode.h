/*!
 *  \~chinese
 *  @header EMErrorCode.h
 *  @abstract SDK定义的错误类型
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header EMErrorCode.h
 *  @abstract SDK defined error type
 *  @author Hyphenate
 *  @version 3.00
 */

typedef enum{
    
    
    
    
    HDErrorGeneral = 1,                      /*! \~chinese 一般错误 \~english General error */
    HDErrorNetworkUnavailable,               /*! \~chinese 网络不可用 \~english Network is unavaliable */
    HDErrorDatabaseOperationFailed,          /*! \~chinese 数据库操作失败 \~english Database operation failed */
    
    
    HDErrorInvalidAppkey = 100,               /*! \~chinese Appkey无效 \~english App key is invalid */
    HDErrorInvalidUsername,                  /*! \~chinese 用户名无效 \~english User name is invalid */
    HDErrorInvalidPassword,                  /*! \~chinese 密码无效 \~english Password is invalid */
    HDErrorInvalidURL,                       /*! \~chinese URL无效 \~english URL is invalid */
    
    HDErrorUserAlreadyLogin = 200,           /*! \~chinese 用户已登录 \~english User has already logged in */
    HDErrorUserNotLogin,                     /*! \~chinese 用户未登录 \~english User has not logged in */
    HDErrorUserAuthenticationFailed,         /*! \~chinese 密码验证失败 \~english Password authentication failed */
    HDErrorUserAlreadyExist,                 /*! \~chinese 用户已存在 \~english User has already existed */
    HDErrorUserNotFound,                     /*! \~chinese 用户不存在 \~english User was not found */
    HDErrorUserIllegalArgument,              /*! \~chinese 参数不合法 \~english Illegal argument */
    HDErrorUserLoginOnAnotherDevice,         /*! \~chinese 当前用户在另一台设备上登录 \~english User has logged in from another device */
    HDErrorUserRemoved,                      /*! \~chinese 当前用户从服务器端被删掉 \~english User was removed from server */
    HDErrorUserRegisterFailed,               /*! \~chinese 用户注册失败 \~english Registration failed */
    HDErrorUpdateApnsConfigsFailed,          /*! \~chinese 更新推送设置失败 \~english Update Apple Push Notification configurations failed */
    HDErrorUserPermissionDenied,             /*! \~chinese 用户没有权限做该操作 \~english User has no access for this operation. */
    
    HDErrorServerNotReachable = 300,         /*! \~chinese 服务器未连接 \~english Server is not reachable */
    HDErrorServerTimeout,                    /*! \~chinese 服务器超时 \~english Server response timeout */
    HDErrorServerBusy,                       /*! \~chinese 服务器忙碌 \~english Server is busy */
    HDErrorServerUnknownError,               /*! \~chinese 未知服务器错误 \~english Unknown server error */
    HDErrorServerGetDNSConfigFailed,         /*! \~chinese 获取DNS设置失败 \~english Get DNS config failure */
    HDErrorServerServingForbidden,           /*! \~chinese 服务被禁用 \~english Serving is forbidden */
    
    HDErrorFileNotFound = 400,               /*! \~chinese 文件没有找到 \~english Can't find the file */
    HDErrorFileInvalid,                      /*! \~chinese 文件无效 \~english File is invalid */
    HDErrorFileUploadFailed,                 /*! \~chinese 上传文件失败 \~english Upload file failure */
    HDErrorFileDownloadFailed,               /*! \~chinese 下载文件失败 \~english Download file failed */
    
    HDErrorMessageInvalid = 500,             /*! \~chinese 消息无效 \~english Message is invalid */
    HDErrorMessageIncludeIllegalContent,      /*! \~chinese 消息内容包含不合法信息 \~english Message contains illegal content */
    HDErrorMessageTrafficLimit,              /*! \~chinese 单位时间发送消息超过上限 \~english Unit time to send messages over the upper limit */
    HDErrorMessageEncryption,                /*! \~chinese 加密错误 \~english Encryption error */
    
    HDErrorCallReasonHangup = 800,
    HDErrorCallReasonNoResponse,
    HDErrorCallReasonReject,
    HDErrorCallReasonBusy,
    HDErrorCallReasonFail,
    HDErrorCallReasonUnspported,
    HDErrorCallReasonOtherDevice,
    HDErrorCallReasonDismiss,
    
    
    VCS_ERR_NET_ERROR                         = 10001,   // "网络错误"
    VCS_ERR_ENGINE_NOT_INITIALIZE             = 10002,   // "引擎未初始化"
    VCS_ERR_INNER_MESSAGE_SEND_FIELD          = 10003,   // "内部信令发送失败"
    VCS_ERR_INNER_ERROR                       = 10004,   // "内部错误",通常因为引擎处于初始化中或销毁中导致当前操作执行失败
    VCS_ERR_RTM_ERROR                         = 10005,   // "内部信令错误"
    VCS_ERR_RTC_ERROR                         = 10006,   // "内部 RTC 错误"
    VCS_ERR_TOKEN_EXPIRED                     = 10007,   // "token 已过期"
    VCS_ERR_TOKEN_INVALID                     = 10008,   // "token 无效"
    VCS_ERR_MESSAGESEND_TO_FAIL               = 10009,   // "发送方为空"
    
    
    
}HDErrorCode;
