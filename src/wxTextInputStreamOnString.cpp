/*
 * wxTextInputStreamOnString.cpp
 */

#include <wxEncodingDetection/wxTextInputStreamOnString.h>

 // ===============================================================================

wxTextInputStreamOnString::wxTextInputStreamOnString(const wxString& s):
    m_charBuffer(s.tchar_str<wxChar>()),
    m_inputStream(m_charBuffer.data(), m_charBuffer.length() * sizeof(wxChar)),
    m_textInputStream(m_inputStream, " \t", m_conv)
{
}

wxTextInputStreamOnString::wxTextInputStreamOnString(const wxTextInputStreamOnString::CharBufferType& charBuffer):
    m_charBuffer(charBuffer),
    m_inputStream(m_charBuffer.data(), m_charBuffer.length() * sizeof(wxChar)),
    m_textInputStream(m_inputStream, " \t", m_conv)
{
}

const wxMemoryInputStream& wxTextInputStreamOnString::GetMemoryStream() const
{
    return m_inputStream;
}

wxTextInputStream& wxTextInputStreamOnString::GetStream()
{
    return m_textInputStream;
}

const wxTextInputStreamOnString::CharBufferType& wxTextInputStreamOnString::GetBuffer() const
{
    return m_charBuffer;
}

wxTextInputStream& wxTextInputStreamOnString::operator *() const
{
    return const_cast<wxTextInputStream&>(m_textInputStream);
}

bool wxTextInputStreamOnString::Eof() const
{
    return m_inputStream.Eof();
}

