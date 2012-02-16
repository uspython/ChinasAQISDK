//
//  ResponseItems.m
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import "ResponseItems.h"

@implementation ResponseItems
@synthesize result=_result;

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

+(ResponseItems*)itemWithDictionary:(NSDictionary*)responseDictionary
{
    return [[[self alloc] initWithDictionary:responseDictionary] autorelease];
}

-(id)initWithDictionary:(NSDictionary*)responseDictionary
{
    self = [self init];
    if (self) {
        _responseDictionary = [responseDictionary retain];
        _result = [self valueForItemKey:@"result"];
    }
    return self;
}

-(NSDictionary*)responseDictionary
{
    return _responseDictionary;
}

-(id)valueForItemKey:(NSString*)key
{
    if (!key) {
        return nil;
    }
    id value = [[self responseDictionary] objectForKey:key];
    if ([value isKindOfClass:[NSNumber class]]) {
        return [value stringValue];
    }
    return value;
    
}

-(void)dealloc
{
    [_responseDictionary release];
    [super dealloc];
}


@end
