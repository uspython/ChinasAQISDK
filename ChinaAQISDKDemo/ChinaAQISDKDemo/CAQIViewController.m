//
//  CAQIViewController.m
//  ChinaAQISDKDemo
//
//  Created by Jianfei Zhao on 2/16/12.
//  Copyright (c) 2012 Jeff Zhao. All rights reserved.
//

#import "CAQIViewController.h"
#import "CAQIRequest.h"
#import "RequestParams.h"
#define RequestUrl @"http://zhaojianfei.com/test/jsontest.php"

@implementation CAQIViewController

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	NSLog(@"I started!!!");
    NSMutableDictionary* theDict=[NSMutableDictionary dictionaryWithObjectsAndKeys:@"helloworld",@"secret_key", nil];
    CAQIRequest* request=[CAQIRequest getRequestWithParams:theDict 
                                                httpMethod:@"POST" 
                                                  delegate:self 
                                                requestURL:RequestUrl];
    [request connect];
    //NSLog(@"responseData:%@",[request])

}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

#pragma mark - CAQIRequest delegate Methods
/**
 * 请求发送给服务器之前调用。
 */
- (void)requestLoading:(CAQIRequest *)request
{
    NSLog(@"Loading request");
}

/**
 * 服务器回应后准备再次发送数据时调用。
 */
- (void)request:(CAQIRequest *)request didReceiveResponse:(NSURLResponse *)response
{
    NSLog(@"didReceiveResponse");
}

/**
 * 错误使请求无法成功时调用。旧方法，为保持兼容存在。
 */
- (void)request:(CAQIRequest *)request didFailWithError:(NSError *)error
{
    NSLog(@"didFailWithError");
}

/**
 * 当收到回应回应并解析为对象后应用。
 *
 * 结果对应可以是dictionary，array，string，number，依赖于API返回的数据。
 */
- (void)request:(CAQIRequest *)request didLoad:(id)result
{
    NSMutableDictionary* theDict=(NSMutableDictionary*)result;
    NSLog(@"WebName is:%@",[theDict objectForKey:@"WebName"]);
    NSLog(@"WebSite is:%@",[theDict objectForKey:@"WebSite"]);
}

/**
 * 请求取消的时候调用。
 */
- (void)request:(CAQIRequest *)request didLoadRawResponse:(NSData *)data
{
    NSLog(@"Cancel request");
}

/**
 * 服务器返回错误或NSConnection delegate方法返回错误时调用。
 */
- (void)request:(CAQIRequest *)request didFailWithROError:(NSError *)error
{
    NSLog(@"Server error");
}

@end
