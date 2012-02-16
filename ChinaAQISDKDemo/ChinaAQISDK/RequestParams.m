//
//  RequestParams.m
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import "RequestParams.h"

@implementation RequestParams
@synthesize method=_method;
@synthesize format=_format;
@synthesize xn_ss=_xn_ss;

-(id)init
{
	if (self = [super init]) {
		self.format = [NSString stringWithFormat:@"JSON"];
		self.xn_ss = [NSString stringWithFormat:@"1"];
	}
	
	return self;
}
-(void)dealloc
{
	self.method = nil;
	self.format = nil;
	self.xn_ss = nil;
	[super dealloc];
}
-(NSMutableDictionary *)requestParamToDictionary
{
    NSMutableDictionary* theDict=[NSMutableDictionary dictionaryWithObjectsAndKeys:
                                  self.method,
                                  "method",
                                  self.format,
                                  "format",
                                  self.xn_ss,
                                  "xn_ss",nil];
    return theDict;
}
-(CAQIResponse *)requestResultToResponse:(id)result
{
    //id responseObject = nil;
	if (![result isKindOfClass:[NSArray class]]) {
		if ([result objectForKey:@"error"] != nil) {
			//responseObject = [ROError errorWithOAuthResult:result];
			//return [CAQIResponse responseWithError:responseObject];
            NSLog(@"error from request:%@",result);
            return [CAQIResponse responseWithRootObject:result];
		}
	}
    
	return [CAQIResponse responseWithRootObject:result];
}


@end
