#ifndef APP_H
#define APP_H

#include <gtkmm.h>

class App : public Gtk::Application
{
protected:
  App();

  void on_activate() override;

public:
  static Glib::RefPtr<App> create();
};

#endif