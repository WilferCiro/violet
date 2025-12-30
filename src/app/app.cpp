#include "app.h"
#include "iostream"

App::App() : Gtk::Application("com.violet.gtkmm4") {}

Glib::RefPtr<App> App::create()
{
  return Glib::RefPtr<App>(new App());
}

void App::on_activate()
{
  Glib::RefPtr<Gtk::Builder> builder;

  try
  {
    builder = Gtk::Builder::create_from_resource(
        "/com/example/violet/ui/mainwindow.ui");
  }
  catch (const Glib::Error &ex)
  {
    std::cerr << "Error cargando UI: "
              << ex.what() << std::endl;
    return;
  }

  auto window = builder->get_object<Gtk::ApplicationWindow>("main_window");

  if (!window)
  {
    std::cerr << "main_window not found in .ui file\n";
    return;
  }

  add_window(*window);
  window->present();
}