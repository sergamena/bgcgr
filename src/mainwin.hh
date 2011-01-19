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

#include<gtkmm.h>

class mainwin:public Gtk::Window
{
public:
	mainwin(void);
	virtual ~mainwin(void){}
protected:
	Gtk::FileChooserDialog*dialog;
	Gtk::ComboBoxEntry*folder;

	void on_choose_folder_clicked(void);
	void on_ok_clicked(void);
	void on_dialog_ok_clicked(void);

	void create_model(void);

	class model_columns:public Gtk::TreeModel::ColumnRecord
	{
	public:
		model_columns(void);
		Gtk::TreeModelColumn<Glib::ustring>folder_path;
	};

	model_columns columns;

	Glib::RefPtr<Gtk::ListStore>folder_model;
};
