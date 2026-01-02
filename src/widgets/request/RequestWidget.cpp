#include "RequestWidget.h"
#include <iostream>
#include <gtkmm/builder.h>
#include "RequestBasicDataWidget.h"
#include "RequestBodyWidget.h"

RequestWidget::RequestWidget() : Gtk::Box()
{
  this->set_orientation(Gtk::Orientation::VERTICAL);
  Glib::RefPtr<Gtk::Builder> builderRequestBasic = Gtk::Builder::create_from_resource("/com/example/violet/ui/requestbasic.ui");
  Glib::RefPtr<Gtk::Builder> builderRequestBody = Gtk::Builder::create_from_resource("/com/example/violet/ui/requestbody.ui");

  auto basicRequestWidget = Gtk::Builder::get_widget_derived<RequestBasicDataWidget>(builderRequestBasic, "parent");
  auto bodyRequestWidget = Gtk::Builder::get_widget_derived<RequestBodyWidget>(builderRequestBody, "parent");
  basicRequestWidget->signal_send().connect([this](BasicData datos)
                                            { std::cout << "El hijo envió datos a: " << datos.url << std::endl; });
  this->append(*basicRequestWidget);
  this->append(*bodyRequestWidget);
}