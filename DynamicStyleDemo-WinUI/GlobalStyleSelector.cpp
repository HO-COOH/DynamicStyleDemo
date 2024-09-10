#include "pch.h"
#include "GlobalStyleSelector.h"
#if __has_include("GlobalStyleSelector.g.cpp")
#include "GlobalStyleSelector.g.cpp"
#endif

namespace winrt::DynamicStyleDemo_WinUI::implementation
{

    winrt::DynamicStyleDemo_WinUI::NullableString GlobalStyleSelector::CurrentStyle()
    {
        return m_currentStyle.empty() ? nullptr : winrt::DynamicStyleDemo_WinUI::NullableString{ m_currentStyle };
    }
    void GlobalStyleSelector::CurrentStyle(winrt::DynamicStyleDemo_WinUI::NullableString const& v)
    {
        if (m_currentStyle != v.Value())
        {
            m_currentStyle = v.Value();
            raisePropertyChange(L"CurrentStyle");
        }
    }

    winrt::Microsoft::UI::Xaml::Style GlobalStyleSelector::GetStyle(
        winrt::hstring const& currentStyle,
        winrt::hstring const& styleKey)
    {
        if (currentStyle.empty() || styleKey.empty())
            return nullptr;

        return winrt::Microsoft::UI::Xaml::Application::Current()
            .Resources()
            .Lookup(winrt::box_value(currentStyle))
            .as<winrt::Microsoft::UI::Xaml::ResourceDictionary>()
            .Lookup(winrt::box_value(styleKey))
            .as<winrt::Microsoft::UI::Xaml::Style>();
    }

    winrt::Microsoft::UI::Xaml::Style GlobalStyleSelector::GetStyle(winrt::hstring const& currentStyle, winrt::hstring const& styleKey, winrt::Microsoft::UI::Xaml::Style const& fallbackStyle)
    {
        return winrt::Microsoft::UI::Xaml::Style();
    }

    winrt::DynamicStyleDemo_WinUI::GlobalStyleSelector GlobalStyleSelector::Instance()
    {
        static winrt::DynamicStyleDemo_WinUI::GlobalStyleSelector s_instance;
        return s_instance;
    }
}
