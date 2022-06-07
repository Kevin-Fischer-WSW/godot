/* zoom_integraton.cpp */

#include "zoom_integration.h"

#include "thirdparty/zoom/h/auth_service_interface.h"
#include "thirdparty/zoom/h/zoom_sdk.h"
#include "thirdparty/zoom/h/zoom_sdk_def.h"
#include "auth_service_event_listener.h"

void ZoomIntegration::add(int p_value) {
	count += p_value;
}

void ZoomIntegration::reset() {
	count = 0;
}

int ZoomIntegration::get_total() const {
    return count;
}

void ZoomIntegration::authorizeSDK() {
	    // Initialize SDK with InitParam object
    ZOOM_SDK_NAMESPACE::InitParam initParam;
    ZOOM_SDK_NAMESPACE::SDKError initReturnVal(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);

    // Set web domain to zoom.us
    initParam.strWebDomain = L"https://zoom.us";
    initReturnVal = ZOOM_SDK_NAMESPACE::InitSDK(initParam);

    // Check if InitSDK call succeeded
    if (initReturnVal == ZOOM_SDK_NAMESPACE::SDKError::SDKERR_SUCCESS)
    {
        // Create IAuthService object to perform Auth actions
        ZOOM_SDK_NAMESPACE::IAuthService* authService;
        ZOOM_SDK_NAMESPACE::SDKError authServiceInitReturnVal = ZOOM_SDK_NAMESPACE::CreateAuthService(&authService);

        if (authServiceInitReturnVal == ZOOM_SDK_NAMESPACE::SDKError::SDKERR_SUCCESS)
        {
            // Create IAuthServiceEvent object to listen for Auth events from SDK
            ZOOM_SDK_NAMESPACE::IAuthServiceEvent* authListener;
            // Auth SDK with AuthContext object
            ZOOM_SDK_NAMESPACE::AuthContext authContext;
            ZOOM_SDK_NAMESPACE::SDKError authCallReturnValue(ZOOM_SDK_NAMESPACE::SDKERR_UNAUTHENTICATION);

            // Call SetEvent to assign your IAuthServiceEvent listener
            AuthServiceEventListener* authEventListener = new AuthServiceEventListener();
            authListener = authEventListener;
            authService->SetEvent(authListener);

            // Provide your JWT to the AuthContext object
            authContext.jwt_token = L"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJhcHBLZXkiOiJ5czAyZEtXYzdSTlBoQkc2VGxYRVNqOWFERnRiRVd6OXpnWDIiLCJpYXQiOjE2NTQ2MzM3MzYsImV4cCI6MTY1NDgwNjUyNiwidG9rZW5FeHAiOjE2NTQ4MDY1MjZ9.LU53JcLM2rx35EDl1DXDNqm5WBdlo2ZYtz1pEBOReRY";

            authCallReturnValue = authService->SDKAuth(authContext);
            if (authCallReturnValue == ZOOM_SDK_NAMESPACE::SDKError::SDKERR_SUCCESS)
            {
                    // SDK Auth in progress
            }

        }
    }
}


void ZoomIntegration::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add", "value"), &ZoomIntegration::add);
    ClassDB::bind_method(D_METHOD("reset"), &ZoomIntegration::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &ZoomIntegration::get_total);
	ClassDB::bind_method(D_METHOD("authorize_SDK"), &ZoomIntegration::authorizeSDK);
}

ZoomIntegration::ZoomIntegration() {
    count = 0;
}
