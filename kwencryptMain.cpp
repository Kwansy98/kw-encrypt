/***************************************************************
 * Name:      kwencryptMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    kw ()
 * Created:   2020-02-16
 * Copyright: kw ()
 * License:
 **************************************************************/

#include "kwencryptMain.h"
#include <wx/msgdlg.h>
#include "DnDialogFile.h"
#include <wx/filename.h>
#include "listData.h"
#include "FileItemMenu.h"
#include <wx/clipbrd.h>
//(*InternalHeaders(kwencryptFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(kwencryptFrame)
const long kwencryptFrame::ID_LISTCTRL1 = wxNewId();
const long kwencryptFrame::ID_BUTTON2 = wxNewId();
const long kwencryptFrame::ID_BUTTON5 = wxNewId();
const long kwencryptFrame::ID_BUTTON3 = wxNewId();
const long kwencryptFrame::ID_BUTTON1 = wxNewId();
const long kwencryptFrame::ID_BUTTON4 = wxNewId();
const long kwencryptFrame::ID_LISTCTRL2 = wxNewId();
const long kwencryptFrame::ID_BUTTON6 = wxNewId();
const long kwencryptFrame::ID_BUTTON7 = wxNewId();
const long kwencryptFrame::ID_BUTTON9 = wxNewId();
const long kwencryptFrame::ID_PANEL2 = wxNewId();
const long kwencryptFrame::ID_PANEL1 = wxNewId();
const long kwencryptFrame::idMenuQuit = wxNewId();
const long kwencryptFrame::idMenuAbout = wxNewId();
const long kwencryptFrame::ID_STATUSBAR1 = wxNewId();
//*)

const long kwencryptFrame::ID_MENU_ORIGINAL_FILE_COPY = wxNewId();
const long kwencryptFrame::ID_MENU_ORIGINAL_FILE_REMOVE = wxNewId();
const long kwencryptFrame::ID_MENU_ORIGINAL_FILE_OPEN_IN_FILE_EXPLORER = wxNewId();


BEGIN_EVENT_TABLE(kwencryptFrame,wxFrame)
    //(*EventTable(kwencryptFrame)
    //*)
END_EVENT_TABLE()

kwencryptFrame::kwencryptFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(kwencryptFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;

    Create(parent, wxID_ANY, _("kw-encryptor"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxCLIP_CHILDREN, _T("wxID_ANY"));
    SetClientSize(wxSize(800,500));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Drag the files you want to encrypt to the box below"));
    listOriginFiles = new wxListCtrl(Panel2, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    StaticBoxSizer1->Add(listOriginFiles, 5, wxALL|wxEXPAND, 1);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    btnAddFile = new wxButton(Panel2, ID_BUTTON2, _("Choose File"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(btnAddFile, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 1);
    btnAddFolder = new wxButton(Panel2, ID_BUTTON5, _("Choose Folder"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer4->Add(btnAddFolder, 0, wxALL|wxEXPAND, 1);
    btnRemove = new wxButton(Panel2, ID_BUTTON3, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(btnRemove, 0, wxALL|wxEXPAND, 1);
    btnRemoveAllOriginFiles = new wxButton(Panel2, ID_BUTTON1, _("Remove All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(btnRemoveAllOriginFiles, 0, wxALL|wxEXPAND, 1);
    BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnEncrypt = new wxButton(Panel2, ID_BUTTON4, _("Encrypt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    btnEncrypt->Disable();
    BoxSizer4->Add(btnEncrypt, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 1);
    StaticBoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 0);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Drag a .KWE file you want to decrypt to the box below"));
    listKweFile = new wxListCtrl(Panel2, ID_LISTCTRL2, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    StaticBoxSizer2->Add(listKweFile, 5, wxALL|wxEXPAND, 1);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(Panel2, ID_BUTTON6, _("Choose .KWE File"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button1->Disable();
    BoxSizer3->Add(Button1, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 1);
    Button2 = new wxButton(Panel2, ID_BUTTON7, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button2->Disable();
    BoxSizer3->Add(Button2, 0, wxALL|wxEXPAND, 1);
    BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(Panel2, ID_BUTTON9, _("Decrypt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    Button4->Disable();
    BoxSizer3->Add(Button4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 1);
    StaticBoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
    BoxSizer2->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel2);
    BoxSizer2->SetSizeHints(Panel2);
    BoxSizer1->Add(Panel2, 5, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    DirDialog1 = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE|wxDD_DIR_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));

    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&kwencryptFrame::OnlistOriginFilesItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&kwencryptFrame::OnlistOriginFilesItemDeselect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&kwencryptFrame::OnlistOriginFilesItemRClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kwencryptFrame::OnbtnAddFileClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kwencryptFrame::OnbtnAddFolderClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kwencryptFrame::OnbtnRemoveClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kwencryptFrame::OnbtnRemoveAllOriginFilesClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kwencryptFrame::OnbtnEncryptClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&kwencryptFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&kwencryptFrame::OnAbout);
    //*)

    SetIcon(wxICON(aMAINICON));

    // 原始文件列表右键弹出菜单
    fileItemMenu = new FileItemMenu();
    fileItemMenu->Append(ID_MENU_ORIGINAL_FILE_COPY, "Copy");
    fileItemMenu->Append(ID_MENU_ORIGINAL_FILE_REMOVE, "Remove");
    fileItemMenu->Append(ID_MENU_ORIGINAL_FILE_OPEN_IN_FILE_EXPLORER, "Open in file explorer");
    Connect(ID_MENU_ORIGINAL_FILE_COPY, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&kwencryptFrame::OnMenuItemCopyOriginalFileSelected);
    Connect(ID_MENU_ORIGINAL_FILE_REMOVE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&kwencryptFrame::OnMenuItemRemoveOriginalFileSelected);
    Connect(ID_MENU_ORIGINAL_FILE_OPEN_IN_FILE_EXPLORER, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&kwencryptFrame::OnMenuItemOpenOriginalFileInExplorerSelected);

    listOriginFiles->SetDropTarget(new DnDialogFile(this)); // 设置原始文件的拖放对话框
    int listCtrlWidth = listOriginFiles->GetSize().GetWidth();
    wxListItem col0; // 第0列表头
    col0.SetId(0);
    col0.SetText("File Name");
    col0.SetWidth(listCtrlWidth / 2);
    col0.SetAlign(wxLIST_FORMAT_LEFT);
    listOriginFiles->InsertColumn(0, col0);
    wxListItem col1; // 第2列表头
    col1.SetId(1);
    col1.SetText("Size");
    col1.SetWidth(listCtrlWidth / 5);
    col1.SetAlign(wxLIST_FORMAT_LEFT);
    listOriginFiles->InsertColumn(1, col1);
    wxListItem col2; // 第3列表头
    col2.SetId(2);
    col2.SetText("Type");
    col2.SetWidth(listCtrlWidth / 5);
    col2.SetAlign(wxLIST_FORMAT_LEFT);
    listOriginFiles->InsertColumn(2, col2);

    printf("[Log] Window initialization successful!\n");
}

kwencryptFrame::~kwencryptFrame()
{
    //(*Destroy(kwencryptFrame)
    //*)
    printf("[Log] Window closed!\n");

    //system("pause");
}

void kwencryptFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void kwencryptFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to kw-encryptor"));
}

void kwencryptFrame::OnClose(wxCloseEvent& event)
{
}

// 添加单个文件（wxFileDialog 默认会将快捷方式 .lnk 转成绝对路径，不知道如何禁用）
void kwencryptFrame::OnbtnAddFileClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_CANCEL) return;
    wxFileName fileName = FileDialog1->GetPath();
    fileItems.push_back(FileItem(fileName.GetFullPath(), fileName.GetHumanReadableSize(), "File"));
    overwriteListCtrl(listOriginFiles, fileItems);
}

// 添加单个目录
void kwencryptFrame::OnbtnAddFolderClick(wxCommandEvent& event)
{
    if (DirDialog1->ShowModal() == wxID_CANCEL) return;
    wxString folderPath = DirDialog1->GetPath();
    fileItems.push_back(FileItem(folderPath, "", "Folder"));
    overwriteListCtrl(listOriginFiles, fileItems);
}

// 移除选中的原始文件
void kwencryptFrame::OnbtnRemoveClick(wxCommandEvent& event)
{
    auto it = fileItems.begin();
    while (it != fileItems.end()) {
        if (it->selected) it = fileItems.erase(it);
        else it++;
    }
    overwriteListCtrl(listOriginFiles, fileItems);
}

// 移除所有原始文件
void kwencryptFrame::OnbtnRemoveAllOriginFilesClick(wxCommandEvent& event)
{
    if (fileItems.empty()) return;
    fileItems.clear();
    listOriginFiles->DeleteAllItems();
    listOriginFiles->Refresh();
}

// 加密文件
void kwencryptFrame::OnbtnEncryptClick(wxCommandEvent& event)
{
}

// 右键列表item
void kwencryptFrame::OnlistOriginFilesItemRClick(wxListEvent& event)
{
    fileItemMenu->itemIndex = event.GetIndex();
    listOriginFiles->PopupMenu(fileItemMenu);
}

// 通过右键菜单复制初始文件列表item
void kwencryptFrame::OnMenuItemCopyOriginalFileSelected(wxCommandEvent& event) {
    //printf("[Log] copy %d\n", fileItemMenu->itemIndex);
    if (wxTheClipboard->Open()) {
        // This data objects are held by the clipboard,
        // so do not delete them in the app.
        wxTheClipboard->SetData( new wxTextDataObject(fileItems[fileItemMenu->itemIndex].fileName.GetFullPath()) );
        wxTheClipboard->Close();
    }
}

// 通过右键菜单移除初始文件列表item
void kwencryptFrame::OnMenuItemRemoveOriginalFileSelected(wxCommandEvent& event)
{
    auto it = fileItems.begin();
    for (int i = 0; i < fileItemMenu->itemIndex; i++) it++;
    fileItems.erase(it);
    overwriteListCtrl(listOriginFiles, fileItems);
}

// 通过右键菜单在文件管理器中浏览文件
void kwencryptFrame::OnMenuItemOpenOriginalFileInExplorerSelected(wxCommandEvent& event)
{
    wxFileName fileName = fileItems[fileItemMenu->itemIndex].fileName;
    wxExecute(wxString("explorer.exe ") << fileName.GetPath());
}

// item 选中
void kwencryptFrame::OnlistOriginFilesItemSelect(wxListEvent& event)
{
    fileItems[event.GetIndex()].selected = true;
}

// item 取消选中
void kwencryptFrame::OnlistOriginFilesItemDeselect(wxListEvent& event)
{
    fileItems[event.GetIndex()].selected = false;
}
