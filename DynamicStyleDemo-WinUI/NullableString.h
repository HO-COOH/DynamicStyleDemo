#pragma once

#include "NullableString.g.h"

namespace winrt::DynamicStyleDemo_WinUI::implementation
{
    struct NullableString : NullableStringT<NullableString>
    {
        NullableString() = default;
        NullableString(winrt::hstring const& v);

        winrt::hstring Value();
        void Value(winrt::hstring const& v);

    private:
        winrt::hstring m_value;
    };
}

namespace winrt::DynamicStyleDemo_WinUI::factory_implementation
{
    struct NullableString : NullableStringT<NullableString, implementation::NullableString>
    {
    };
}
