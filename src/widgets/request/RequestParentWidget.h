#ifndef REQUEST_PARENT_WIDGET_H
#define REQUEST_PARENT_WIDGET_H

#include <gtkmm/notebook.h>
#include <gtkmm/box.h>
#include <iostream>

class RequestParentWidget: public Gtk::Notebook
{
public:
    RequestParentWidget();

protected:
  Gtk::Box* getTabBox(const std::string &title);
};

#endif // REQUEST_PARENT_WIDGET_H