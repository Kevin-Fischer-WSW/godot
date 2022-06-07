#pragma once
#include "thirdparty/zoom/h/auth_service_interface.h"

class AuthServiceEventListener : public ZOOM_SDK_NAMESPACE::IAuthServiceEvent {
public:
	void onAuthenticationReturn(ZOOMSDK::AuthResult ret) override;
	void onLoginReturnWithReason(ZOOMSDK::LOGINSTATUS ret, ZOOMSDK::IAccountInfo *pAccountInfo, ZOOMSDK::LoginFailReason reason) override;
	void onLogout() override;
	void onZoomAuthIdentityExpired() override;
	void onZoomIdentityExpired() override;
};
