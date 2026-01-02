#ifndef REQUEST_BASIC_DATA_WIDGET_H
#define REQUEST_BASIC_DATA_WIDGET_H

#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include "../../models/structs/request/BasicDataStructure.h"

class RequestBasicDataWidget: public Gtk::Box
{
public:
    RequestBasicDataWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    

    sigc::signal<void(BasicData)> signal_send();
protected:
    void on_button_clicked(); // El callback interno del botón de tu .ui

    sigc::signal<void(BasicData)> m_signal_send;
    Gtk::Entry *urlEntry;
    Gtk::Entry *nameEntry;
    Gtk::ComboBoxText *methodComboBox;
    Gtk::Button *sendButton;
    BasicData getData();
};

#endif // REQUEST_BASIC_DATA_WIDGET_H