#include "NavBarWidget.h"
#include <gtkmm/box.h>
#include <gtkmm/label.h>

NavBarWidget::NavBarWidget()
{
  Gtk::Label *label = Gtk::manage(new Gtk::Label("Collections"));
  this->addTab("Collections", *label);
  label->show();
  Gtk::Label *label2 = Gtk::manage(new Gtk::Label("History"));
  this->addTab("History", *label2);
  label2->show();
}

void NavBarWidget::addTab(const std::string &tabName, Gtk::Widget &child)
{
  Gtk::Box *tabContent = Gtk::manage(new Gtk::Box(Gtk::Orientation::VERTICAL));
  tabContent->prepend(child);
  tabContent->show();

  append_page(*tabContent, tabName);
}