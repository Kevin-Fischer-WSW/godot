/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "zoom_integration.h"

void register_zoom_types() {
    ClassDB::register_class<ZoomIntegration>();
}

void unregister_zoom_types() {
   // Nothing to do here in this example.
}
