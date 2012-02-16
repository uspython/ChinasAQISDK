//
//  RequestParams.h
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CAQIResponse.h"

@interface RequestParams : NSObject
{
    NSString* _method;
    NSString* _format;
    NSString* _xn_ss;
}
//请求方法
@property (nonatomic,copy) NSString* method;
//返回数据的格式
@property (nonatomic,copy) NSString* format;
//返回值的格式
@property (nonatomic,copy) NSString* xn_ss;

//将参数封装到字典
-(NSMutableDictionary*)requestParamToDictionary;
//将返回的数据整理为CAQIResponse
-(CAQIResponse *)requestResultToResponse:(id)result;


@end
