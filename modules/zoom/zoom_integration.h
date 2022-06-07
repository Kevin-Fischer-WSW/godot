/* zoom_integration.h */

#ifndef ZOOM_INTEGRATION_H
#define ZOOM_INTEGRATION_H

#include "core/reference.h"

class ZoomIntegration : public Reference {
    GDCLASS(ZoomIntegration, Reference);

    int count;

protected:
    static void _bind_methods();

public:
    void add(int p_value);
    void reset();
    int get_total() const;

	void authorizeSDK();

    ZoomIntegration();
};

#endif // ZOOM_INTEGRATION_H
