/***************************************************************
 * Name:      kwencryptMain.h
 * Purpose:   Defines Application Frame
 * Author:    kw ()
 * Created:   2020-02-16
 * Copyright: kw ()
 * License:
 **************************************************************/

#ifndef KWENCRYPTMAIN_H
#define KWENCRYPTMAIN_H

//(*Headers(kwencryptFrame)
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class kwencryptFrame: public wxFrame
{
    friend class DnDialogFile;
    public:

        kwencryptFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~kwencryptFrame();

    private:

        //(*Handlers(kwencryptFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        void OnbtnRemoveClick(wxCommandEvent& event);
        void OnbtnAddFileClick(wxCommandEvent& event);
        void OnbtnRemoveAllClick(wxCommandEvent& event);
        void OnbtnRemoveClick1(wxCommandEvent& event);
        void OnbtnEncryptClick(wxCommandEvent& event);
        void OnbtnAddFolderClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(kwencryptFrame)
        static const long ID_LISTBOX1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON5;
        static const long ID_BUTTON3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON4;
        static const long ID_LISTBOX2;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_BUTTON9;
        static const long ID_PANEL2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(kwencryptFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button4;
        wxButton* btnAddFile;
        wxButton* btnAddFolder;
        wxButton* btnEncrypt;
        wxButton* btnRemove;
        wxButton* btnRemoveAll;
        wxDirDialog* DirDialog1;
        wxFileDialog* FileDialog1;
        wxListBox* ListBox1;
        wxListBox* ListBox2;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // KWENCRYPTMAIN_H
