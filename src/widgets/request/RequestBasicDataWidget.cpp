#include "RequestBasicDataWidget.h"
#include <gtkmm/entry.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include "../../models/structs/request/BasicDataStructure.h"

RequestBasicDataWidget::RequestBasicDataWidget(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
    : Gtk::Box(cobject)
{
  nameEntry = builder->get_widget<Gtk::Entry>("name");
  urlEntry = builder->get_widget<Gtk::Entry>("url");
  methodComboBox = builder->get_widget<Gtk::ComboBoxText>("method");

  sendButton = builder->get_widget<Gtk::Button>("send_btn");
  sendButton->signal_clicked().connect(
      sigc::mem_fun(*this, &RequestBasicDataWidget::on_button_clicked));
}

sigc::signal<void(BasicData)> RequestBasicDataWidget::signal_send()
{
  return m_signal_send;
}

void RequestBasicDataWidget::on_button_clicked()
{
  BasicData datos = getData();
  m_signal_send.emit(datos);
}

BasicData RequestBasicDataWidget::getData()
{
  BasicData data;
  data.name = nameEntry->get_text();
  data.url = urlEntry->get_text();
  data.method = methodComboBox->get_active_text();
  return data;
}