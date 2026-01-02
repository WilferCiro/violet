#ifndef NAVBAR_WIDGET_H
#define NAVBAR_WIDGET_H

#include <gtkmm/notebook.h>

class NavBarWidget: public Gtk::Notebook
{
public:
    NavBarWidget();
  private:
    void addTab(const std::string& tabName, Gtk::Widget &child);
};

#endif