#include "RequestParentWidget.h"
#include <gtkmm/notebook.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include "RequestWidget.h"
#include <string>

RequestParentWidget::RequestParentWidget() : Gtk::Notebook()
{
  this->set_scrollable(true);
  this->set_show_tabs(true);

  auto request_widget = Gtk::make_managed<RequestWidget>();
  auto request_widget2 = Gtk::make_managed<RequestWidget>();

  auto tab_box = this->getTabBox("Request 1");
  auto tab_box2 = this->getTabBox("Request 2");

  int page = this->append_page(*request_widget, *tab_box);
  int page2 = this->append_page(*request_widget2, *tab_box2);

}

Gtk::Box* RequestParentWidget::getTabBox(const std::string &title)
{

  auto tab_box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  auto label = Gtk::make_managed<Gtk::Label>(title);
  auto close_btn = Gtk::make_managed<Gtk::Button>();
  close_btn->set_icon_name("window-close-symbolic");

  tab_box->append(*label);
  tab_box->append(*close_btn);
  tab_box->set_margin_top(2);
  tab_box->set_margin_bottom(2);

  /*/
  close_btn->signal_clicked().connect([this, page]()
                                      { this->remove_page(page); });*/
  return tab_box;
}