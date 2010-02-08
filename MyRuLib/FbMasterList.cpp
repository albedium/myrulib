#include "FbMasterList.h"
#include "FbConst.h"

BEGIN_EVENT_TABLE(FbMasterList, FbTreeListCtrl)
	EVT_FB_AUTHOR(ID_EMPTY_MASTERS, FbMasterList::OnEmptyMasters)
	EVT_FB_AUTHOR(ID_APPEND_MASTER, FbMasterList::OnAppendMaster)
END_EVENT_TABLE()

FbMasterList::FbMasterList(wxWindow *parent, wxWindowID id)
	:FbTreeListCtrl(parent, id, wxTR_HIDE_ROOT | wxTR_NO_LINES | wxTR_FULL_ROW_HIGHLIGHT | wxTR_COLUMN_LINES | wxSUNKEN_BORDER)
{
}

void FbMasterList::OnAppendMaster(FbMasterEvent& event)
{
	FbTreeListUpdater updater(this);
	wxTreeItemId root = GetRootItem();

	wxTreeItemIdValue cookie;
	wxTreeItemId child = GetFirstChild(root, cookie);

	wxTreeItemId item = AppendItem(root, event.GetString(), -1, -1, new FbMasterData(event.m_master, FT_AUTHOR));
	wxString number = wxString::Format(wxT("%d"), event.m_number);
	SetItemText(item, 1, number);

	if (!child.IsOk()) SelectItem(item);
}

void FbMasterList::OnEmptyMasters(FbMasterEvent& event)
{
	FbTreeListUpdater updater(this);
	DeleteRoot();
	AddRoot(wxEmptyString);
}

