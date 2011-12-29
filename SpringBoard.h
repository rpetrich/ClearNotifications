#import <SpringBoard/SpringBoard.h>

@class BBContent, BBSound, BBAttachments, BBAssertion, BBObserver;

@interface BBAction : NSObject <NSCopying, NSCoding> {
@private
	id _internalBlock;
	BOOL _hasCallblock;
	BOOL _canBypassPinLock;
	NSURL* _launchURL;
	NSString* _launchBundleID;
	int replyType;
}
@property(assign, nonatomic) int replyType;
@property(assign, nonatomic) BOOL hasCallblock;
@property(copy, nonatomic) id internalBlock;
@property(assign, nonatomic) BOOL canBypassPinLock;
@property(copy, nonatomic) NSString* launchBundleID;
@property(retain, nonatomic) NSURL* launchURL;
+(id)actionWithTextReplyCallblock:(id)textReplyCallblock;
+(id)actionWithLaunchBundleID:(NSString *)launchBundleID callblock:(id)callblock;
+(id)actionWithLaunchURL:(NSURL *)launchURL callblock:(id)callblock;
+(id)actionWithCallblock:(id)callblock;
-(id)description;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(id)copyWithZone:(NSZone*)zone;
-(NSString *)partialDescription;
-(void)deliverResponse:(id)response;
-(NSString *)bundleID;
-(NSURL *)url;
-(BOOL)isAppLaunchAction;
-(BOOL)isURLLaunchAction;
-(BOOL)wantsTextReply;
-(BOOL)hasLaunchInfo;
-(void)dealloc;
-(id)_initWithInternalCallblock:(id)internalCallblock replyType:(int)type;
-(id)initWithTextReplyCallblock:(id)textReplyCallblock;
-(id)initWithCallblock:(id)callblock;
@end

@interface BBBulletin : NSObject <NSCopying, NSCoding> {
@private
	NSString* _sectionID;
	NSString* _publisherRecordID;
	NSString* _publisherBulletinID;
	int _addressBookRecordID;
	int _sectionSubtype;
	BBContent* _content;
	BBContent* _modalAlertContent;
	NSDate* _date;
	NSDate* _endDate;
	NSDate* _recencyDate;
	int _dateFormatStyle;
	BOOL _dateIsAllDay;
	NSTimeZone* _timeZone;
	int _accessoryStyle;
	BOOL _clearable;
	BBSound* _sound;
	BBAttachments* _attachments;
	NSString* _unlockActionLabelOverride;
	NSMutableDictionary* _actions;
	NSArray* _buttons;
	BOOL _expiresOnPublisherDeath;
	NSDictionary* _context;
	NSDate* _expirationDate;
	NSString* _bulletinID;
	NSDate* _lastInterruptDate;
	BBAssertion* _lifeAssertion;
	BBObserver* _observer;
	unsigned realertCount_deprecated;
	NSSet* alertSuppressionAppIDs_deprecated;
}
@property(copy, nonatomic) NSSet* alertSuppressionAppIDs_deprecated;
@property(assign, nonatomic) unsigned realertCount_deprecated;
@property(retain, nonatomic) BBObserver* observer;
@property(retain, nonatomic) BBAssertion* lifeAssertion;
@property(copy, nonatomic) BBAction* expireAction;
@property(retain, nonatomic) NSDate* expirationDate;
@property(retain, nonatomic) NSMutableDictionary* actions;
@property(copy, nonatomic) NSString* unlockActionLabelOverride;
@property(retain, nonatomic) BBAttachments* attachments;
@property(retain, nonatomic) BBContent* content;
@property(retain, nonatomic) NSDate* lastInterruptDate;
@property(retain, nonatomic) NSDictionary* context;
@property(assign, nonatomic) BOOL expiresOnPublisherDeath;
@property(copy, nonatomic) NSArray* buttons;
@property(copy, nonatomic) BBAction* replyAction;
@property(copy, nonatomic) BBAction* acknowledgeAction;
@property(copy, nonatomic) BBAction* defaultAction;
@property(readonly, assign, nonatomic) int primaryAttachmentType;
@property(retain, nonatomic) BBSound* sound;
@property(assign, nonatomic) BOOL clearable;
@property(assign, nonatomic) int accessoryStyle;
@property(retain, nonatomic) NSTimeZone* timeZone;
@property(assign, nonatomic) BOOL dateIsAllDay;
@property(assign, nonatomic) int dateFormatStyle;
@property(retain, nonatomic) NSDate* recencyDate;
@property(retain, nonatomic) NSDate* endDate;
@property(retain, nonatomic) NSDate* date;
@property(retain, nonatomic) BBContent* modalAlertContent;
@property(copy, nonatomic) NSString* message;
@property(copy, nonatomic) NSString* subtitle;
@property(copy, nonatomic) NSString* title;
@property(assign, nonatomic) int sectionSubtype;
@property(assign, nonatomic) int addressBookRecordID;
@property(copy, nonatomic) NSString* publisherBulletinID;
@property(copy, nonatomic) NSString* recordID;
@property(copy, nonatomic) NSString* sectionID;
@property(copy, nonatomic) NSString* section;
@property(copy, nonatomic) NSString* bulletinID;
+(id)bulletinWithBulletin:(id)bulletin;
-(id)description;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(id)copyWithZone:(NSZone*)zone;
-(void)_fillOutCopy:(id)copy withZone:(NSZone*)zone;
-(void)deliverResponse:(id)response;
-(id)responseSendBlock;
-(id)responseForExpireAction;
-(id)responseForButtonActionAtIndex:(unsigned)index;
-(id)responseForAcknowledgeAction;
-(id)responseForReplyAction;
-(id)responseForDefaultAction;
-(id)_responseForActionKey:(id)actionKey;
-(id)_actionKeyForButtonIndex:(unsigned)buttonIndex;
-(id)attachmentsCreatingIfNecessary:(BOOL)necessary;
-(unsigned)numberOfAdditionalAttachmentsOfType:(int)type;
-(unsigned)numberOfAdditionalAttachments;
-(id)init;
-(void)dealloc;
@end

@interface BBBulletinRequest : BBBulletin {
}
@property(assign, nonatomic) BOOL tentative;
@property(assign, nonatomic) BOOL showsUnreadIndicator;
@property(assign, nonatomic) unsigned realertCount;
@property(copy, nonatomic) NSString* section;
@property(assign, nonatomic) BOOL expiresOnPublisherDeath;
@property(copy, nonatomic) BBAction* expireAction;
@property(retain, nonatomic) NSDate* expirationDate;
@property(copy, nonatomic) NSArray* buttons;
@property(copy, nonatomic) BBAction* replyAction;
@property(copy, nonatomic) BBAction* acknowledgeAction;
@property(copy, nonatomic) BBAction* defaultAction;
@property(assign, nonatomic) int primaryAttachmentType;
@property(retain, nonatomic) BBSound* sound;
@property(assign, nonatomic) BOOL clearable;
@property(assign, nonatomic) int accessoryStyle;
@property(retain, nonatomic) NSTimeZone* timeZone;
@property(assign, nonatomic) BOOL dateIsAllDay;
@property(assign, nonatomic) int dateFormatStyle;
@property(retain, nonatomic) NSDate* recencyDate;
@property(retain, nonatomic) NSDate* endDate;
@property(retain, nonatomic) NSDate* date;
@property(retain, nonatomic) BBContent* modalAlertContent;
@property(copy, nonatomic) NSString* message;
@property(copy, nonatomic) NSString* subtitle;
@property(copy, nonatomic) NSString* title;
@property(assign, nonatomic) int sectionSubtype;
@property(assign, nonatomic) int addressBookRecordID;
@property(copy, nonatomic) NSString* publisherBulletinID;
@property(copy, nonatomic) NSString* recordID;
@property(copy, nonatomic) NSString* sectionID;
-(void)generateBulletinID;
-(void)addAlertSuppressionAppID:(id)anId;
-(void)setUnlockActionLabel:(id)label;
-(void)withdraw;
-(void)publish;
-(void)publish:(BOOL)publish;
-(void)addButton:(id)button;
-(void)addAttachmentOfType:(int)type;
-(void)setContextValue:(id)value forKey:(id)key;
@end

@interface SBAwayBulletinListItem : NSObject {
	NSMutableArray* _bulletins;
	int _personID;
	NSString* _contactInfo;
	BBBulletin* _activeBulletin;
	NSDate* _sortDate;
	NSDate* _displayDate;
	NSString* _message;
	UIImage* _listItemImage;
}
-(id)initWithBulletin:(BBBulletin *)bulletin;
-(void)dealloc;
-(id)bulletinWithID:(id)anId;
-(void)_update;
-(void)addBulletin:(BBBulletin *)bulletin;
-(void)removeBulletin:(BBBulletin *)bulletin;
-(void)modifyBulletin:(BBBulletin *)bulletin;
-(BOOL)containsBulletinWithID:(id)anId;
-(NSDate *)sortDate;
-(NSArray *)bulletins;
-(BBBulletin *)activeBulletin;
-(NSString *)message;
-(NSString *)title;
-(NSDate *)date;
-(NSString *)subtitle;
-(NSUInteger)maxMessageLines;
-(NSString *)description;
-(UIImage *)iconImage;
-(UIImage *)attachmentImageForKey:(id)key;
-(NSString *)attachmentText;
-(BOOL)hasSamePersonAsBulletin:(BBBulletin *)bulletin;
-(BOOL)canCoalesceWithBulletin:(BBBulletin *)bulletin;
@end

@class SBAwayBulletinCell, SBAwayBulletinListView, SBAwayListUnlockActionContext;

@interface SBAwayBulletinListController : NSObject <UITableViewDataSource, UITableViewDelegate> {
	BBObserver* _observer;
	NSMutableArray* _listItems;
	NSMutableArray* _realertTimers;
	SBAwayBulletinCell* _unlockingCell;
	BOOL _lockBarIsTracking;
	SBAwayBulletinCell* _trackingCell;
	SBAwayBulletinListView* _view;
	CGRect _viewRect;
	float _contentHeight;
	BOOL _dimmed;
	BOOL _presentingNewBulletin;
	BOOL _dimmingForLockButtonPress;
	BOOL _hibernating;
	CGAffineTransform _pinnedViewTransform;
	SBAwayListUnlockActionContext* _unlockActionContext;
	NSMutableArray* _pendingSystemAlerts;
	id _itemToBlink;
	id _itemToFloat;
}
@property(readonly, assign, nonatomic) UIView* view;
@property(assign, nonatomic) BOOL dimmed;
@property(assign, nonatomic) CGRect viewRect;
@property(readonly, assign, nonatomic) BOOL lockBarIsTracking;
@property(readonly, assign, nonatomic) NSArray* listItems;
@property(readonly, assign, nonatomic) BOOL presentingNewBulletin;
-(id)init;
-(void)dealloc;
-(void)clearViewsAndHibernate;
-(void)rebuildViewsAndStopHibernating;
-(BOOL)isHibernating;
-(void)setUnlockActionContext:(SBAwayListUnlockActionContext *)context;
-(void)showTestBulletin;
-(SBAwayBulletinListItem *)_listItemForNewBulletin:(BBBulletin *)newBulletin;
-(id)_listItemContainingBulletinID:(id)anId;
-(id)_systemAlertItem;
-(void)_sortListItems;
-(SBAwayListUnlockActionContext *)unlockActionContext;
-(void)setTableItemToBlink:(id)blink;
-(void)grabEnded;
-(void)setTableItemToFloat:(id)aFloat force:(BOOL)force;
-(void)setTableItemToFloat:(id)aFloat;
-(void)_awayControllerRelocked:(id)relocked;
-(void)setUnlockingTableViewCell:(id)cell;
-(void)lockBarStartedTrackingForCell:(id)cell;
-(void)lockBarStoppedTracking;
-(void)resetLockBarIfTracking;
-(void)_alertForBulletin:(id)bulletin;
-(void)_realertTimerFired:(id)fired;
-(void)_killRealerts:(id)realerts;
-(void)_scheduleRealerts:(id)realerts;
-(void)_hardwareButtonPressed:(id)pressed;
-(int)_rowAnimationForInsert;
-(int)_rowAnimationForDelete;
-(void)_updateModelAndTableViewForAddition:(id)addition;
-(void)_updateModelAndTableViewForModification:(id)modification originalHeight:(float)height;
-(void)_updateModelAndTableViewForRemoval:(id)removal originalHeight:(float)height;
-(void)observer:(id)observer addBulletin:(id)bulletin forFeed:(unsigned)feed;
-(void)observer:(id)observer modifyBulletin:(id)bulletin;
-(void)observer:(id)observer removeBulletin:(id)bulletin;
-(BOOL)observerShouldFetchAttachmentImageBeforeBulletinDelivery:(id)observer;
-(id)observer:(id)observer multipleThumbnailSizeConstraintsForAttachmentType:(int)attachmentType;
-(id)observer:(id)observer composedAttachmentImageForType:(int)type thumbnailData:(id)data key:(id)key;
-(void)activateAlertItem:(id)item didUndimScreen:(BOOL)screen;
-(void)deactivateAlertItem:(id)item;
-(id)pendOrDeactivateAlertItemsForUnlock;
-(int)tableView:(id)view numberOfRowsInSection:(int)section;
-(void)_setContentForTableCell:(id)tableCell withItem:(id)item floating:(BOOL)floating;
-(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
-(BOOL)tableView:(id)view canEditRowAtIndexPath:(id)indexPath;
-(float)tableView:(id)view heightForRowAtIndexPath:(id)indexPath;
-(void)scrollViewDidEndDragging:(id)scrollView willDecelerate:(BOOL)decelerate;
-(double)animationDelayForShowPasscodeUI:(BOOL)showPasscodeUI duration:(double)duration;
-(double)animationDurationForShowPasscodeUI:(BOOL)showPasscodeUI duration:(double)duration;
-(void)setViewHiddenForUnlock:(BOOL)unlock;
-(void)setViewHiddenForUnlock:(BOOL)unlock force:(BOOL)force;
-(void)setPinnedViewTransform:(CGAffineTransform)transform;
-(void)_configureAndPositionView;
-(float)_rowHeightForItem:(id)item floating:(BOOL)floating;
@end

@interface SBAwayView (OS50)
- (SBAwayBulletinListController *)bulletinController;
@end

@protocol SBBulletinDateLabel;

@interface SBBulletinCellContentViewBase : UIView {
	UILabel* _titleLabel;
	UILabel* _subtitleLabel;
	UILabel* _messageLabel;
	UILabel<SBBulletinDateLabel>* _dateLabel;
	UIImageView* _attachmentImageView;
	UILabel* _attachmentLabel;
	unsigned _maxMessageLines;
	unsigned _maxTitleLines;
	CGSize _imageSize;
	UIColor* _shadowColor;
	int _layoutStyle;
	float _titleLineHeight;
	float _subtitleLineHeight;
	float _messageLineHeight;
	float _attachmentLineHeight;
	BOOL _highlighted;
	int _dateFormatStyle;
}
@property(retain, nonatomic) UILabel* titleLabel;
@property(retain, nonatomic) UILabel* subtitleLabel;
@property(retain, nonatomic) UILabel* messageLabel;
@property(retain, nonatomic) UILabel* attachmentLabel;
@property(retain, nonatomic) UILabel<SBBulletinDateLabel>* dateLabel;
@property(retain, nonatomic) UIImageView* attachmentImageView;
@property(assign, nonatomic, getter=isHighlighted) BOOL highlighted;
@property(assign, nonatomic) int layoutStyle;
@property(assign, nonatomic) int dateFormatStyle;
-(id)_initForLayoutStyle:(int)layoutStyle;
-(id)initForBulletinStyle;
-(id)initForSystemAlertStyle;
-(void)dealloc;
-(void)setTitleMaxLines:(NSUInteger)lines;
-(void)setMessageMaxLines:(NSUInteger)lines;
-(void)setShadowColor:(UIColor *)color;
-(id)_modifiedLabel:(UILabel *)label withText:(NSString *)text font:(UIFont *)font alignment:(UITextAlignment)alignment;
-(id)_modifiedLabel:(UILabel *)label withText:(NSString *)text font:(UIFont *)font;
-(void)setTitle:(NSString *)title;
-(void)setSubtitle:(NSString *)subtitle;
-(void)setMessage:(NSString *)message;
-(void)setAttachmentText:(NSString *)text;
-(void)dateLabelDidChange:(UILabel *)dateLabel;
-(void)setStartDate:(NSDate *)startDate endDate:(NSDate *)endDate timeZone:(NSTimeZone *)zone allDay:(BOOL)isAllDay formatStyle:(int)style;
-(void)setAttachmentImage:(UIImage *)image;
-(void)setAttachmentImageSize:(CGSize)size;
-(void)_updateLabelFontsAndLineHeights;
-(CGFloat)_heightForLabel:(UILabel *)label forWidth:(CGFloat)width minLines:(NSUInteger)minLines maxLines:(NSUInteger)maxLines lineHeight:(CGFloat)lineHeight;
-(CGFloat)_heightForLabel:(UILabel *)label forWidth:(CGFloat)width maxHeight:(CGFloat)height;
-(void)_configureLabel:(UILabel *)label withFont:(UIFont *)font alignment:(UITextAlignment)alignment;
-(UIFont *)_dateFont;
-(UIFont *)_titleFont;
-(UIFont *)_subtitleFont;
-(UIFont *)_messageFont;
-(UIFont *)_attachmentFont;
@end

@class SBBulletinLockBar;

@interface SBAwayListUnlockActionContext : NSObject {
	NSString* _lockLabel;
	NSString* _shortLockLabel;
	id _unlockAction;
	NSString* _bulletinID;
	CGFloat _fontsize;
	BOOL _launchActionCanBypassPinLock;
	BOOL _canBypassPinLock;
}
@property(assign, nonatomic) BOOL canBypassPinLock;
+(id)unlockActionContextForBulletin:(BBBulletin *)bulletin;
+(id)unlockActionContextForAlertItem:(id)alertItem;
-(id)_initWithLockLabel:(id)lockLabel shortLockLabel:(id)label unlockAction:(id)action bulletinID:(id)anId;
-(id)_initWithLockLabel:(id)lockLabel shortLockLabel:(id)label unlockAction:(id)action bulletinID:(id)anId fontSize:(float)size;
-(void)dealloc;
-(id)unlockAction;
-(id)lockLabel;
-(id)shortLockLabel;
-(id)bulletinID;
-(float)lockLabelFontSize;
@end

@interface SBAwayListItemCell : UITableViewCell {
	UIImageView* _separator;
	UIImageView* _iconImageView;
	SBBulletinCellContentViewBase* _cellContentView;
	SBAwayBulletinListController* _controller;
	BOOL _shouldBlinkIcon;
}
@property(assign, nonatomic) BOOL shouldBlinkIcon;
+(float)_rowHeightForContentHeight:(float)contentHeight;
+(float)_contentWidthForRowWidth:(float)rowWidth;
+(float)_cellIconLeftPadding;
+(float)_cellContentLeftPadding;
+(float)_cellContentRightPadding;
+(float)_cellContentTopPadding;
+(float)_cellContentExtraPadding;
-(BOOL)_hasBackgroundColor;
-(void)_addIconBlinkAnimation;
-(void)_removeIconBlinkAnimation;
-(void)_createContentView;
-(id)initWithReuseIdentifier:(id)reuseIdentifier;
-(void)dealloc;
-(void)setIconImage:(id)image;
-(void)setTitle:(id)title;
-(void)setMessage:(id)message;
-(void)layoutSubviews;
-(BOOL)_drawsSeparator;
-(CGRect)_contentRect;
-(CGRect)_cellContentViewFrame;
-(void)setController:(id)controller;
@end

@interface SBAwayBulletinCell : SBAwayListItemCell {
	SBBulletinLockBar* _lockBar;
	SBAwayListUnlockActionContext* _actionContext;
	BOOL _disableUnlockSound;
}
@property(readonly, assign, nonatomic) SBAwayListUnlockActionContext* actionContext;
+(float)rowHeightForSubtitle:(id)subtitle message:(id)message maxLines:(unsigned)lines rowWidth:(float)width;
+(float)rowHeightForSubtitle:(id)subtitle imageHeight:(float)height;
-(void)_createContentView;
-(void)dealloc;
-(void)setMaxMessageLines:(unsigned)lines;
-(void)setSubtitle:(id)subtitle;
-(void)setStartDate:(id)date endDate:(id)date2 timeZone:(id)zone allDay:(BOOL)day formatStyle:(int)style;
-(void)setAttachmentImage:(id)image;
-(void)setAttachmentText:(id)text;
-(void)layoutSubviews;
-(void)setUnlockActionContext:(id)context;
-(void)setDisableUnlockSound:(BOOL)sound;
-(void)resetLockBar;
-(void)lockBarUnlocked:(id)unlocked;
-(void)lockBarStartedTracking:(id)tracking;
-(void)lockBarStoppedTracking:(id)tracking;
-(void)lockBarSlidBackToOrigin:(id)origin;
-(void)_lockBarSlidBackToOrigin:(id)origin withDuration:(double)duration;
-(id)hitTest:(CGPoint)test withEvent:(id)event;
@end
