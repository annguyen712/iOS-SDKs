#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICollectionViewItemRegistration.h>)
//
//  UICollectionViewItemRegistration.h
//  UIKit
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//
#import <UIKit/UIKitDefines.h>

@class UINib, UICollectionViewCell, UICollectionReusableView;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef void(^UICollectionViewCellRegistrationConfigurationHandler)(__kindof UICollectionViewCell * _Nonnull cell, NSIndexPath * _Nonnull indexPath, id _Nonnull item) API_UNAVAILABLE(watchos);

// Cell Registration

UIKIT_EXTERN API_AVAILABLE(ios(14.0), tvos(14.0)) API_UNAVAILABLE(watchos) NS_SWIFT_UI_ACTOR
@interface UICollectionViewCellRegistration : NSObject

+ (instancetype)registrationWithCellClass:(Class)cellClass configurationHandler:(UICollectionViewCellRegistrationConfigurationHandler)configurationHandler;
+ (instancetype)registrationWithCellNib:(UINib*)cellNib configurationHandler:(UICollectionViewCellRegistrationConfigurationHandler)configurationHandler API_DEPRECATED("Loading Interface Builder products will not be supported in a future version of visionOS.", visionos(1.0, 1.0));

@property(nonatomic,readonly,nullable) Class cellClass;
@property(nonatomic,readonly,nullable) UINib *cellNib;
@property(nonatomic,readonly) UICollectionViewCellRegistrationConfigurationHandler configurationHandler;

@end

// Supplementary Registration

typedef void(^UICollectionViewSupplementaryRegistrationConfigurationHandler)(__kindof UICollectionReusableView * _Nonnull supplementaryView, NSString * _Nonnull elementKind, NSIndexPath * _Nonnull indexPath) API_UNAVAILABLE(watchos);

UIKIT_EXTERN API_AVAILABLE(ios(14.0), tvos(14.0)) API_UNAVAILABLE(watchos) NS_SWIFT_UI_ACTOR
@interface UICollectionViewSupplementaryRegistration : NSObject

+ (instancetype)registrationWithSupplementaryClass:(Class)supplementaryClass elementKind:(NSString*)elementKind  configurationHandler:(UICollectionViewSupplementaryRegistrationConfigurationHandler)configurationHandler;
+ (instancetype)registrationWithSupplementaryNib:(UINib*)supplementaryNib elementKind:(NSString*)elementKind configurationHandler:(UICollectionViewSupplementaryRegistrationConfigurationHandler)configurationHandler API_DEPRECATED("Loading Interface Builder products will not be supported in a future version of visionOS.", visionos(1.0, 1.0));

@property(nonatomic,readonly,nullable) Class supplementaryClass;
@property(nonatomic,readonly,nullable) UINib *supplementaryNib;
@property(nonatomic,readonly) NSString *elementKind;
@property(nonatomic,readonly) UICollectionViewSupplementaryRegistrationConfigurationHandler configurationHandler;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UICollectionViewItemRegistration.h>
#endif
