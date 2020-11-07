#pragma once

#include <QtWidgets/QWidget>

#include "software/gui/robot_diagnostics/widgets/slider.h"

// This include is autogenerated by the .ui file in the same folder
// The generated version will be names 'ui_<filename>.h'
#include "software/gui/robot_diagnostics/ui/ui_main_widget.h"

/**
 * Set up dribbler area of the widget
 *
 * @param widget widget to setup
 * @param dribbler_power_changed_callback callback for when dribbler power input changes
 */
void setupDribbler(Ui::AutoGeneratedMainWidget *widget,
                   std::function<void(double)> dribbler_power_changed_callback);
