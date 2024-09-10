#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::DynamicStyleDemo_WinUI::implementation
{

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

    void MainWindow::ComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
    {
        auto selection = winrt::unbox_value<winrt::hstring>(sender.as<winrt::Microsoft::UI::Xaml::Controls::ComboBox>().SelectedItem());
        winrt::DynamicStyleDemo_WinUI::GlobalStyleSelector::Instance().CurrentStyle(winrt::DynamicStyleDemo_WinUI::NullableString{ selection });
        OutputDebugString(selection.data());
    }

}
