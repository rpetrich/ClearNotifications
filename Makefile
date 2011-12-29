TWEAK_NAME = ClearNotifications
ClearNotifications_FILES = Tweak.x
ClearNotifications_FRAMEWORKS = Foundation UIKit CoreGraphics

ADDITIONAL_CFLAGS = -std=c99

include framework/makefiles/common.mk
include framework/makefiles/tweak.mk
