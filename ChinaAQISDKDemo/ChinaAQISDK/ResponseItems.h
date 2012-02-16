//
//  ResponseItems.h
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ResponseItems : NSObject
{
    NSDictionary* _responseDictionary;
    NSString* _result;
}
@property (nonatomic,readonly) NSString* result;

/**
 * 生成一个ResponseItems 
 * @param responseDictionary 传入的由json解析完后字典对象
 * 返回一个ResponseItems
 */
+(ResponseItems*)itemWithDictionary:(NSDictionary*)responseDictionary;
/*
 *初始化ResponseItems
 */
-(id)initWithDictionary:(NSDictionary*)responseDictionary;

/*
 *表示对应的json字典对象。 
 */
-(NSDictionary*)responseDictionary;


-(id)valueForItemKey:(NSString*)key;
@end
