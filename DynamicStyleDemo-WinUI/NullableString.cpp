#include "pch.h"
#include "NullableString.h"
#if __has_include("NullableString.g.cpp")
#include "NullableString.g.cpp"
#endif

namespace winrt::DynamicStyleDemo_WinUI::implementation
{

    NullableString::NullableString(winrt::hstring const& v) : m_value{v}
    {
    }
    winrt::hstring NullableString::Value()
    {
        return m_value;
    }
    void NullableString::Value(winrt::hstring const& v)
    {
        m_value = v;
    }
}
