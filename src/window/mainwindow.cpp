#include "mainwindow.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::ApplicationWindow(cobject)
{
  // ejemplo: conectar widgets desde el builder
  Gtk::Button* b = nullptr;
  //builder->get_widget("button_add_collection", b);
  //if (b) b->signal_clicked().connect([this](){ hide(); });
}