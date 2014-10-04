//
//  QNUploader.h
//  QiniuSDK
//
//  Created by bailong on 14-9-28.
//  Copyright (c) 2014年 Qiniu. All rights reserved.
//

#import <Foundation/Foundation.h>

@class QNResponseInfo;

typedef void (^QNUpProgressBlock)(NSString *key, float percent);
typedef void (^QNUpCompleteBlock)(QNResponseInfo *info, NSString *key, NSDictionary *resp);
typedef BOOL (^QNUpCancelBlock)(void);

@interface QNUploadOption : NSObject

@property (copy, nonatomic) NSDictionary *params;
@property (copy, nonatomic) NSString *mimeType;
@property BOOL checkCrc;
@property (copy) QNUpProgressBlock progress;
@property (copy) QNUpCancelBlock cancelToken;

@end

@interface QNUploadManager : NSObject

- (void)putData:(NSData *)data
            key:(NSString *)key
          token:(NSString *)token
       complete:(QNUpCompleteBlock)block
         option:(QNUploadOption *)option;

- (void)putFile:(NSString *)filePath
            key:(NSString *)key
          token:(NSString *)token
       complete:(QNUpCompleteBlock)block
         option:(QNUploadOption *)option;

@end
