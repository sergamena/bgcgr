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
	//declaring pointers on widgets
	Gtk::VBox*main_vbox;
	Gtk::HBox*hbox;
	Gtk::Button*choose_folder;
	//creating window
	set_title(_("Desktop background"));
	set_border_width(5);
	add(*(main_vbox=Gtk::manage(new Gtk::VBox)));

	main_vbox->pack_start(*(hbox=Gtk::manage(new Gtk::HBox)),Gtk::PACK_SHRINK);
	
	hbox->pack_start(*Gtk::manage(new Gtk::Label(_("Choose folder:"))),
			 Gtk::PACK_SHRINK);

	main_vbox->pack_start(*(hbox=Gtk::manage(new Gtk::HBox)),Gtk::PACK_SHRINK);

	hbox->pack_start(*(folder=Gtk::manage(new Gtk::ComboBoxEntry)));
	hbox->pack_start(*(choose_folder=Gtk::manage(new Gtk::Button)));

	//main_vbox->pack_start(*Gtk::);

	show_all();
}
