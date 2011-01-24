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
#include<set>

class mainwin:public Gtk::Window
{
public:
	mainwin(void);
	virtual ~mainwin(void){}
protected:
	//widgets
	Gtk::FileChooserDialog*dialog;
	Gtk::ComboBoxEntry*folder;
	//signal handlers
	void on_choose_folder_clicked(void);
	void on_ok_clicked(void);
	void on_dialog_ok_clicked(void);
	//methods
	void create_model(void);
	void read_history(void);
	void write_history(void);
	//column record for comboboxentry
	class folder_columns:public Gtk::TreeModel::ColumnRecord
	{
	public:
		folder_columns(void);
		Gtk::TreeModelColumn<Glib::ustring>folder_path;
	};

	folder_columns columns;
	//model for comboboxentry
	Glib::RefPtr<Gtk::ListStore>folder_model;
	//data
	std::set<Glib::ustring>history_list;
	std::string history_file;
};
