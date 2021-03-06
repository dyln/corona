//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DevPasswordDlg.h"

// CDevPasswordDlg dialog

IMPLEMENT_DYNAMIC(CDevPasswordDlg, CDialog)

CDevPasswordDlg::CDevPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDevPasswordDlg::IDD, pParent),
      m_sUser( "" ),
      m_sPassword( "" )
{
}

CDevPasswordDlg::~CDevPasswordDlg()
{
}

void CDevPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CDevPasswordDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Login/OK btn starts disabled
    GetDlgItem( IDOK )->EnableWindow( FALSE );    

    // Set (non-editable) username
	CStatic *pUser = (CStatic *)GetDlgItem( IDC_LOGIN_EMAIL );
	pUser->SetWindowTextW( m_sUser );

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_MESSAGE_MAP(CDevPasswordDlg, CDialog)
	ON_EN_CHANGE(IDC_LOGIN_PASSWORD, &CDevPasswordDlg::OnChangeInfo)
END_MESSAGE_MAP()


// CDevPasswordDlg message handlers
void CDevPasswordDlg::OnChangeInfo()
{
    CString sPassword;
    GetDlgItemText( IDC_LOGIN_PASSWORD, sPassword );

    GetDlgItem( IDOK )->EnableWindow( !sPassword.IsEmpty() );    
}

// Just remember password, don't do authorization checks
void CDevPasswordDlg::OnOK()  // OnLogin()
{
    // Retrieve password value
    GetDlgItemText( IDC_LOGIN_PASSWORD, m_sPassword );

	CDialog::OnOK();
}
