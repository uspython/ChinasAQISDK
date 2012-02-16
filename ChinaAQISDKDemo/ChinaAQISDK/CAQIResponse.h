//
//  CAQIResponse.h
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>


@class RequestParams;
@interface CAQIResponse : NSObject
{
    id _rootObject;
    NSError *_error;
    RequestParams *_param;
}

/**
* 接口返回的正确处理对象
* 对象类型：ResponseItems | NSArray 
*/
@property(nonatomic, retain)id rootObject;
/**
 * 接口返回的错误对象.
 */
@property(nonatomic, retain)NSError *error;
/**
 * 接口请求的参数对象
 * 用于调用者判断是那个接口返回的response;
 */
@property(nonatomic, retain)RequestParams *param;
/**
 * 返回由Rest接口正确信息构建的Response对象.
 */
+(CAQIResponse *)responseWithRootObject:(id)rootObject;
/**
 * 返回由Rest接口错误信息构建的Response对象.
 */
+(CAQIResponse *)responseWithError:(NSError *)error;
@end
