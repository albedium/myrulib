#ifndef __FBLOGSTREAM_H__
#define __FBLOGSTREAM_H__

#include <wx/wx.h>
#include <wx/log.h>
#include <wx/thread.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>

#ifdef FB_SYSLOG_LOGGING

class FbLogSyslog: public wxLog
{
	public:
		FbLogSyslog();
		virtual ~FbLogSyslog();
	protected:
		virtual void DoLog(wxLogLevel level, const wxChar *szString, time_t t);
		virtual void PostMsg(wxLogLevel level, const wxChar *szString, time_t t);
	private:
		static wxCriticalSection sm_queue;
};

#else // FB_SYSLOG_LOGGING

class FbLogStream: public wxLog
{
	public:
		FbLogStream();
	protected:
		virtual void DoLog(wxLogLevel level, const wxChar *szString, time_t t);
		virtual void DoLogString(const wxChar *szString, time_t t);
		virtual void PostMsg(wxLogLevel level, const wxChar *szString, time_t t);
	private:
		static wxCriticalSection sm_queue;
		wxFileOutputStream m_stream;
		wxTextOutputStream m_text;
};

#endif // FB_SYSLOG_LOGGING

#endif // __FBLOGSTREAM_H__
