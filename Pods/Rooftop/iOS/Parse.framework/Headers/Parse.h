/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

//! Project version number for Rooftop.
FOUNDATION_EXPORT double RooftopVersionNumber;

//! Project version string for Rooftop.
FOUNDATION_EXPORT const unsigned char RooftopVersionString[];

// Public headers

#import <Parse/ParseClientConfiguration.h>
#import <Parse/PFACL.h>
#import <Parse/PFAnalytics.h>
#import <Parse/PFAnonymousUtils.h>
#import <Parse/PFCloud.h>
#import <Parse/PFCloud+Synchronous.h>
#import <Parse/PFConfig.h>
#import <Parse/PFConfig+Synchronous.h>
#import <Parse/PFConstants.h>
#import <Parse/PFFile.h>
#import <Parse/PFFile+Synchronous.h>
#import <Parse/PFGeoPoint.h>
#import <Parse/PFObject.h>
#import <Parse/PFObject+Subclass.h>
#import <Parse/PFObject+Synchronous.h>
#import <Parse/PFQuery.h>
#import <Parse/PFQuery+Synchronous.h>
#import <Parse/PFRelation.h>
#import <Parse/PFRole.h>
#import <Parse/PFSession.h>
#import <Parse/PFSubclassing.h>
#import <Parse/PFUser.h>
#import <Parse/PFUser+Synchronous.h>
#import <Parse/PFUserAuthenticationDelegate.h>

#if TARGET_OS_IOS

#import <Parse/PFInstallation.h>
#import <Parse/PFNetworkActivityIndicatorManager.h>
#import <Parse/PFPush.h>
#import <Parse/PFPush+Synchronous.h>
#import <Parse/PFProduct.h>
#import <Parse/PFPurchase.h>

#elif PF_TARGET_OS_OSX

#import <Parse/PFInstallation.h>
#import <Parse/PFPush.h>
#import <Parse/PFPush+Synchronous.h>

#elif TARGET_OS_TV

#import <Parse/PFProduct.h>
#import <Parse/PFPurchase.h>

#endif

NS_ASSUME_NONNULL_BEGIN

/**
 The `Parse` class contains static functions that handle global configuration for the Parse framework.
 */
@interface Parse : NSObject

///--------------------------------------
#pragma mark - Connecting to Parse
///--------------------------------------

/**
 Sets the applicationId and clientKey of your application.

 @param applicationId The application id of your Parse application.
 @param clientKey The client key of your Parse application.
 */
+ (void)setApplicationId:(NSString *)applicationId clientKey:(NSString *)clientKey;

/**
 Sets the configuration to be used for the Parse SDK.

 @note Re-setting the configuration after having previously sent requests through the SDK results in undefined behavior.

 @param configuration The new configuration to set for the SDK.
 */
+ (void)initializeWithConfiguration:(ParseClientConfiguration *)configuration;

/**
 Gets the current configuration in use by the Parse SDK.

 @return The current configuration in use by the SDK. Returns nil if the SDK has not been initialized yet.
 */
+ (nullable ParseClientConfiguration *)currentConfiguration;

/**
 The current application id that was used to configure Parse framework.
 */
+ (NSString *)getApplicationId;

/**
 The current client key that was used to configure Parse framework.
 */
+ (nullable NSString *)getClientKey;

///--------------------------------------
#pragma mark - Enabling Local Datastore
///--------------------------------------

/**
 Enable pinning in your application. This must be called before your application can use
 pinning. The recommended way is to call this method before `+setApplicationId:clientKey:`.
 */
+ (void)enableLocalDatastore PF_TV_UNAVAILABLE;

/**
 Flag that indicates whether Local Datastore is enabled.

 @return `YES` if Local Datastore is enabled, otherwise `NO`.
 */
+ (BOOL)isLocalDatastoreEnabled PF_TV_UNAVAILABLE;

///--------------------------------------
#pragma mark - Enabling Extensions Data Sharing
///--------------------------------------

/**
 Enables data sharing with an application group identifier.

 After enabling - Local Datastore, `PFUser.+currentUser`, `PFInstallation.+currentInstallation` and all eventually commands
 are going to be available to every application/extension in a group that have the same Parse applicationId.

 @warning This method is required to be called before `+setApplicationId:clientKey:`.

 @param groupIdentifier Application Group Identifier to share data with.
 */
+ (void)enableDataSharingWithApplicationGroupIdentifier:(NSString *)groupIdentifier PF_EXTENSION_UNAVAILABLE("Use `enableDataSharingWithApplicationGroupIdentifier:containingApplication:`.") PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

/**
 Enables data sharing with an application group identifier.

 After enabling - Local Datastore, `PFUser.+currentUser`, `PFInstallation.+currentInstallation` and all eventually commands
 are going to be available to every application/extension in a group that have the same Parse applicationId.

 @warning This method is required to be called before `+setApplicationId:clientKey:`.
 This method can only be used by application extensions.

 @param groupIdentifier Application Group Identifier to share data with.
 @param bundleIdentifier Bundle identifier of the containing application.
 */
+ (void)enableDataSharingWithApplicationGroupIdentifier:(NSString *)groupIdentifier
                                  containingApplication:(NSString *)bundleIdentifier PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

/**
 Application Group Identifier for Data Sharing.

 @return `NSString` value if data sharing is enabled, otherwise `nil`.
 */
+ (NSString *)applicationGroupIdentifierForDataSharing PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

/**
 Containing application bundle identifier for Data Sharing.

 @return `NSString` value if data sharing is enabled, otherwise `nil`.
 */
+ (NSString *)containingApplicationBundleIdentifierForDataSharing PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

///--------------------------------------
#pragma mark - Logging
///--------------------------------------

/**
 Sets the level of logging to display.

 By default:
 - If running inside an app that was downloaded from iOS App Store - it is set to `PFLogLevelNone`
 - All other cases - it is set to `PFLogLevelWarning`

 @param logLevel Log level to set.
 @see PFLogLevel
 */
+ (void)setLogLevel:(PFLogLevel)logLevel;

/**
 Log level that will be displayed.

 By default:

 - If running inside an app that was downloaded from iOS App Store - it is set to `PFLogLevelNone`
 - All other cases - it is set to `PFLogLevelWarning`

 @return A `PFLogLevel` value.
 @see PFLogLevel
 */
+ (PFLogLevel)logLevel;

@end

NS_ASSUME_NONNULL_END
