#ifndef REQUESTBODYWIDGET_CPP
#define REQUESTBODYWIDGET_CPP

#include <gtkmm/builder.h>
#include <gtkmm/paned.h>

class RequestBodyWidget: public Gtk::Paned
{
public:
  RequestBodyWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
private:
};


#endif // REQUESTBODYWIDGET_CPP