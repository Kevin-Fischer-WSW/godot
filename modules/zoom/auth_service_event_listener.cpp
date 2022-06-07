#include "auth_service_event_listener.h"

#include "core/print_string.h"
#include "thirdparty/zoom/h/auth_service_interface.h"

void AuthServiceEventListener::onAuthenticationReturn(ZOOMSDK::AuthResult ret) {
	if (ret == ZOOM_SDK_NAMESPACE::AUTHRET_JWTTOKENWRONG)
	{
		// SDK Auth call failed because the JWT token is invalid.
		print_line("Zoom was not authenticated");
	}
	else if (ret == ZOOM_SDK_NAMESPACE::SDKError::SDKERR_SUCCESS)
	{
		print_line("Zoom authenticated");
	}
}

void AuthServiceEventListener::onLoginReturnWithReason(ZOOMSDK::LOGINSTATUS ret, ZOOMSDK::IAccountInfo *pAccountInfo, ZOOMSDK::LoginFailReason reason) {
}

void AuthServiceEventListener::onLogout() {
}

void AuthServiceEventListener::onZoomAuthIdentityExpired() {
}

void AuthServiceEventListener::onZoomIdentityExpired() {
}
