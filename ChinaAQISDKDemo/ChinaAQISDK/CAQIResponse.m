//
//  CAQIResponse.m
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import "CAQIResponse.h"


@implementation CAQIResponse
@synthesize rootObject = _rootObject;
@synthesize error = _error;
@synthesize param = _param;

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

-(void)dealloc
{
    [_rootObject release];
    [_error release];
    [_param release];
    [super dealloc];
}

+(CAQIResponse *)responseWithRootObject:(id)rootObject
{
    CAQIResponse *response = [[self alloc] init];
    response.rootObject = rootObject;
    return [response autorelease];
    
}

+(CAQIResponse *)responseWithError:(NSError *)error
{
    CAQIResponse *response = [[self alloc] init];
    response.error = error;
    return [response autorelease];
}


@end
