#ifndef GTKMM_MAIN_WINDOW_H
#define GTKMM_MAIN_WINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow
{
public:
  MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
  virtual ~MainWindow() = default;
};

#endif