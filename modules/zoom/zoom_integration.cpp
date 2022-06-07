/* zoom_integraton.cpp */

#include "zoom_integration.h"

void ZoomIntregration::add(int p_value) {
    count += p_value;
}

void ZoomIntregration::reset() {
    count = 0;
}

int ZoomIntregration::get_total() const {
    return count;
}

void ZoomIntregration::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add", "value"), &ZoomIntregration::add);
    ClassDB::bind_method(D_METHOD("reset"), &ZoomIntregration::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &ZoomIntregration::get_total);
}

ZoomIntregration::ZoomIntregration() {
    count = 0;
}
