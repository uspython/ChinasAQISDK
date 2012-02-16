//
//  CAQIRequest.h
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CAQIRequestDelegate;
@class RequestParams;
@class CAQIResponse;

@interface CAQIRequest : NSObject
{
    id<CAQIRequestDelegate> _delegate;
    NSString* _url;
    NSString* _httpMethod; 
    NSMutableDictionary* _param;
    NSURLConnection* _connection;
    NSMutableData* _responseData;
    
    RequestParams* _requestParamObject;
    CAQIResponse* _responseObject;
}

@property(nonatomic, assign) id<CAQIRequestDelegate> delegate;

@property(nonatomic, copy) NSString *url;

@property(nonatomic, copy) NSString *httpMethod;

@property(nonatomic, retain) NSMutableDictionary *params;

@property(nonatomic, assign) NSURLConnection *connection;

@property(nonatomic, assign) NSMutableData *responseData;

@property(nonatomic, retain) RequestParams *requestParamObject;

@property(nonatomic, retain) CAQIResponse *responseObject;

+(CAQIRequest *)getRequestWithParam:(RequestParams *)param httpMethod:(NSString *)httpMethod delegate:(id<CAQIRequestDelegate>)delegate requestURL:(NSString *)url;
+ (CAQIRequest *)getRequestWithParams:(NSMutableDictionary *)params httpMethod:(NSString *)httpMethod delegate:(id<CAQIRequestDelegate>)delegate requestURL:(NSString *)url;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
+ (id)getRequestSessionKeyWithParams:(NSString *)url;

+ (NSString*)serializeURL:(NSString *)baseUrl params:(NSDictionary *)params;

+ (NSString*)serializeURL:(NSString *)baseUrl params:(NSDictionary *)params httpMethod:(NSString *)httpMethod;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

- (void) connect;

@end

////////////////////////////////////////////////////////////////////////////////
/*
 * CAQIRequestDelegate protocol definition.
 */
@protocol CAQIRequestDelegate <NSObject>

@optional

/**
 * 请求发送给服务器之前调用。
 */
- (void)requestLoading:(CAQIRequest *)request;

/**
 * 服务器回应后准备再次发送数据时调用。
 */
- (void)request:(CAQIRequest *)request didReceiveResponse:(NSURLResponse *)response;

/**
 * 错误使请求无法成功时调用。旧方法，为保持兼容存在。
 */
- (void)request:(CAQIRequest *)request didFailWithError:(NSError *)error;

/**
 * 当收到回应回应并解析为对象后应用。
 *
 * 结果对应可以是dictionary，array，string，number，依赖于API返回的数据。
 */
- (void)request:(CAQIRequest *)request didLoad:(id)result;

/**
 * 请求取消的时候调用。
 */
- (void)request:(CAQIRequest *)request didLoadRawResponse:(NSData *)data;

/**
 * 服务器返回错误或NSConnection delegate方法返回错误时调用。
 */
- (void)request:(CAQIRequest *)request didFailWithROError:(NSError *)error;

@end
