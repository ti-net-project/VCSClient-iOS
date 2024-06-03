
typedef enum{
    VCS_ERR_NET_ERROR                         = 10001,   // "网络错误"
    VCS_ERR_ENGINE_NOT_INITIALIZE             = 10002,   // "引擎未初始化"
    VCS_ERR_INNER_MESSAGE_SEND_FIELD          = 10003,   // "内部信令发送失败"
    VCS_ERR_INNER_ERROR                       = 10004,   // "内部错误",通常因为引擎处于初始化中或销毁中导致当前操作执行失败
    VCS_ERR_RTM_ERROR                         = 10005,   // "内部信令错误"
    VCS_ERR_RTC_ERROR                         = 10006,   // "内部 RTC 错误"
    VCS_ERR_TOKEN_EXPIRED                     = 10007,   // "token 已过期"
    VCS_ERR_TOKEN_INVALID                     = 10008,   // "token 无效"
    VCS_ERR_MESSAGESEND_TO_FAIL               = 10009,   // "发送方为空"
    VCS_ERR_Interface_ERROR                   = 10010,   // "接口返回错误"
    VCS_ERR_GENERAL                           = 10011,   // "本地错误"
    
    
    
}HDErrorCode;
