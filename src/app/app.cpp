#include "app.h"
#include "iostream"
#include "../widgets/navbar/NavBarWidget.h"
#include "../widgets/request/RequestBasicDataWidget.h"
#include "../widgets/request/RequestParentWidget.h"

App::App() : Gtk::Application("com.violet.gtkmm4") {}

Glib::RefPtr<App> App::create()
{
  return Glib::RefPtr<App>(new App());
}

void App::on_activate()
{
  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_resource("/com/example/violet/ui/mainwindow.ui");

  auto window = builder->get_object<Gtk::ApplicationWindow>("main_window");

  if (!window)
  {
    std::cerr << "main_window not found in .ui file\n";
    return;
  }

  add_window(*window);
  window->present();

  auto mainPaned = builder->get_object<Gtk::Paned>("main_paned");
  mainPaned->set_start_child(*Gtk::make_managed<NavBarWidget>());
  mainPaned->set_end_child(*Gtk::make_managed<RequestParentWidget>());
}