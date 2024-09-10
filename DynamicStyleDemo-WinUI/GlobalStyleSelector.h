#pragma once

#include "GlobalStyleSelector.g.h"
#include "PropertyChangeHelper.hpp"

namespace winrt::DynamicStyleDemo_WinUI::implementation
{
    struct GlobalStyleSelector : GlobalStyleSelectorT<GlobalStyleSelector>, MvvmHelper::PropertyChangeHelper<GlobalStyleSelector>
    {
        GlobalStyleSelector() = default;

        winrt::DynamicStyleDemo_WinUI::NullableString CurrentStyle();
        void CurrentStyle(winrt::DynamicStyleDemo_WinUI::NullableString const& v);

        static winrt::Microsoft::UI::Xaml::Style GetStyle(
            winrt::hstring const& currentStyle,
            winrt::hstring const& styleKey
        );
        static winrt::Microsoft::UI::Xaml::Style GetStyle(
            winrt::hstring const& currentStyle,
            winrt::hstring const& styleKey,
            winrt::Microsoft::UI::Xaml::Style const& fallbackStyle
        );
        static winrt::DynamicStyleDemo_WinUI::GlobalStyleSelector Instance();
    private:
        winrt::hstring m_currentStyle;
    };
}

namespace winrt::DynamicStyleDemo_WinUI::factory_implementation
{
    struct GlobalStyleSelector : GlobalStyleSelectorT<GlobalStyleSelector, implementation::GlobalStyleSelector>
    {
    };
}
