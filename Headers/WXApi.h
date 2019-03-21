//
//  WXApi.h
//  所有Api接口
//
//  Created by Wechat on 12-2-28.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WXApiObject.h"

#pragma mark - WXApiDelegate

/*! @brief Receive and process event messages from WeChat
 *
 * Receive and process event messages from WeChat.
 * Meanwhile WeChat will switch to the third-party app.
 * WXApiDelegate is used and triggered in handleOpenURL.
 */
@protocol WXApiDelegate <NSObject>
@optional

/*! @brief Receive and process request from WeChat and call sendResp
 *
 * The third-party app receives a request from WeChat.
 * After asynchronous processing of the request.
 * sendResp should be called to send the result to WeChat.
 * Possible requests include GetMessageFromWXReq, ShowMessageFromWXReq, etc.
 * @param req Specific request contents (auto-released)
 */
- (void)onReq:(BaseReq *)req;

/*! @brief Response of sendReq from WeChat
 *
 * The third-party app receives the result from WeChat.
 * If sendReq is called, onResp will be received.
 * Possible results include SendMessageToWXResp, etc.
 * @param Specific response contents (auto-released)
 */
- (void)onResp:(BaseResp *)resp;

@end

#pragma mark - WXApi

/*! @brief WeChat API interface functions
 *
 * This class envelopes all interfaces of WeChat SDK
 */
@interface WXApi : NSObject

/*! @brief Member function of WXApi. It's used to register the third-party app in WeChat.
 *
 * It should be called whenever WeChat enables the third-party app.
 * The app will appear in Available Apps in WeChat.
 * @param appid WeChat Developer ID
 * @return Yes (success) or No (failure)
 */
+ (BOOL)registerApp:(NSString *)appid;

/*! @brief A member function of WXApi, used for the application registration of third parties in WeChat client program
 *
 * Needs to be called when a third-party application starts each time. It will show in the list of available
 * applications on WeChat after the first call.
 * @param appid WeChat developer ID
 * @param appdesc Additional application description, no longer than 1024 bytes
 * @return Return ‘YES’ if success, otherwise return ‘NO’.
 */
+ (BOOL)registerApp:(NSString *)appid withDescription:(NSString *)appdesc;

/*! @brief WXApi的成员函数，向微信终端程序注册应用支持打开的文件类型。
 *
 * 需要在每次启动第三方应用程序时调用。调用后并第一次成功分享数据到微信后，会在微信的可用应用列表中出现。
 * @see registerApp
 * @param typeFlag 应用支持打开的数据类型, enAppSupportContentFlag枚举类型 “|” 操作后结果
 */
+ (void)registerAppSupportContentFlag:(UInt64)typeFlag;

/*! @brief Process the data transferred while WeChat enable the app through URL
 *
 * Call in application:openURL:sourceApplication:annotation: or application:handleOpenURL
 * @param url URL used to enable the app
 * @param delegate  Object of WXApiDelegate. It's used to receive messages that trigger WeChat
 * @return Yes (success) or No (failure)
 */
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<WXApiDelegate>)delegate;

/*! @brief Check whether the user has installed WeChat
 *
 * @return Yes (WeChat installed) or No (WeChat not installed)
 */
+ (BOOL)isWXAppInstalled;

/*! @brief Check whether the current WeChat version supports OpenApi
 *
 * @return Yes (support) or No (do not support)
 */
+ (BOOL)isWXAppSupportApi;

/*! @brief Get installation URL of WeChat in iTunes
 *
 * @return strings about installation URL of WeChat
 */
+ (NSString *)getWXAppInstallUrl;

/*! @brief Get the current SDK version
 *
 * @return the current SDK version
 */
+ (NSString *)getApiVersion;

/*! @brief Open WeChat
 *
 * @return Yes (success) or No (failure)
 */
+ (BOOL)openWXApp;

/*! @brief Send a request to WeChat and wait for onResp returned from WeChat
 *
 *The third-party app calls this function, switches to WeChat interface and
 * waits for onResp returned from WeChat. WeChat must calls onResp after the
 * asynchronous processing. Possible requests include SendMessageToWXReq, etc.
 * @param req Specific request. It should be auto-released after calling the function.
 * @return Yes (success) or No (failure)
 */
+ (BOOL)sendReq:(BaseReq *)req;

/*! @brief 发送Auth请求到微信，支持用户没安装微信，等待微信返回onResp
 *
 * 函数调用后，会切换到微信的界面。第三方应用程序等待微信返回onResp。微信在异步处理完成后一定会调用onResp。支持SendAuthReq类型。
 * @param req 具体的发送请求，在调用函数后，请自己释放。
 * @param viewController 当前界面对象。
 * @param delegate  WXApiDelegate对象，用来接收微信触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)sendAuthReq:(SendAuthReq *)req
     viewController:(UIViewController *)viewController
           delegate:(id<WXApiDelegate>)delegate;

/*! @brief Send the response of onReq request from WeChat and go to WeChat interface
 *
 * When this function is called, WeChat interface is open.
 * The third-party app receives onResp request from WeChat, processes this request
 * asynchronously and calls this function.
 * Possible requests include GetMessageFromWXResp, ShowMessageFromWXResp, etc.
 * @param resp Specific response. It should be auto-released after calling the function.
 * @return Yes (success) or No (failure)
 */
+ (BOOL)sendResp:(BaseResp *)resp;

@end
