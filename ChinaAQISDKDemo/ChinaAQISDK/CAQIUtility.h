//
//  CAQIUtility.h
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CAQIUtility : NSObject
/**
 * 解析URL参数的工具方法。
 */
+ (NSDictionary *)parseURLParams:(NSString *)query;

/*
 * 使用传入的baseURL地址和参数集合构造含参数的请求URL的工具方法。
 */
+ (NSURL*)generateURL:(NSString*)baseURL params:(NSDictionary*)params;

/*
 * 根据指定的参数名，从URL中找出并返回对应的参数值。
 */
+ (NSString *)getValueStringFromUrl:(NSString *)url forParam:(NSString *)param;

/**
 * 对输入的字符串进行MD5计算并输出验证码的工具方法。
 */
+ (NSString *)md5HexDigest:(NSString *)input;

/**
 * 对字符串进行URL编码转换。
 */
+ (NSString*)encodeString:(NSString*)string urlEncode:(NSStringEncoding)encoding;

/**
 * 将日期字符串转换为字符串类型。
 */
+ (NSDate *)getDateFromString:(NSString *)dateTime;


@end
