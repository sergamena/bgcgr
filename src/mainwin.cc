/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include<glib/gi18n.h>

#include"mainwin.hh"

mainwin::mainwin(void)
{
	Gtk::VBox*main_vbox;
	Gtk::HBox*hbox;
	Gtk::HButtonBox*button_box;
	Gtk::Button*choose_folder;
	Gtk::Button*ok;
	Gtk::Button*cancel;

	set_title(_("Desktop background"));
	set_border_width(5);

	add(*(main_vbox=Gtk::manage(new Gtk::VBox)));

	main_vbox->pack_start(*(hbox=Gtk::manage(new Gtk::HBox)),
		Gtk::PACK_SHRINK);
	main_vbox->set_size_request(390);

	hbox->pack_start(*Gtk::manage(new Gtk::Label(
		_("Choose folder:"))),Gtk::PACK_SHRINK);

	main_vbox->pack_start(*(hbox=Gtk::manage(new Gtk::HBox)),
		Gtk::PACK_SHRINK,5);

	create_model();

	hbox->pack_start(*(folder=Gtk::manage(new Gtk::ComboBoxEntry(
		folder_model))));

	hbox->pack_start(*(choose_folder=Gtk::manage(new Gtk::Button)),
		Gtk::PACK_SHRINK);

	choose_folder->set_image(*(Gtk::manage(new Gtk::Image(
		Gtk::Stock::DIRECTORY,Gtk::ICON_SIZE_BUTTON))));
	choose_folder->signal_clicked().connect(sigc::mem_fun(*this,
		&mainwin::on_choose_folder_clicked));

	main_vbox->pack_start(*(button_box=Gtk::manage(
		new Gtk::HButtonBox(Gtk::BUTTONBOX_END,5))),
		Gtk::PACK_SHRINK);

	button_box->pack_start(*(ok=Gtk::manage(new Gtk::Button(
		Gtk::Stock::OK))));
	button_box->pack_start(*(cancel=Gtk::manage(new Gtk::Button(
		Gtk::Stock::CANCEL))));
	
	cancel->signal_clicked().connect(sigc::mem_fun(*this,
		&mainwin::hide));

	show_all();
}

void mainwin::on_choose_folder_clicked(void)
{
	dialog=new Gtk::FileChooserDialog(_("Choose folder"),
		Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);

	Gtk::Button*ok=dialog->add_button(Gtk::Stock::OK,
		Gtk::RESPONSE_OK);
	Gtk::Button*cancel=dialog->add_button(Gtk::Stock::CANCEL,
		Gtk::RESPONSE_CANCEL);
	ok->signal_clicked().connect(sigc::mem_fun(*this,
		&mainwin::on_dialog_ok_clicked));

	dialog->run();
	delete dialog;
}

void mainwin::on_dialog_ok_clicked(void)
{
	folder->get_entry()->set_text(dialog->get_filename());
}

void mainwin::create_model(void)
{
	folder_model=Gtk::ListStore::create(columns);
	Gtk::TreeModel::Row row=*folder_model->append();
	row[columns.folder_path]="/usr/share/backgrounds";
}

mainwin::model_columns::model_columns(void)
{
	add(folder_path);
}
