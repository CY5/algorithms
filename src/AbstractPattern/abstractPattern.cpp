/*
    Abstract Design Pattern Implementation based on
    https://www.bogotobogo.com/DesignPatterns/abstractfactorymethod.php 
*/
#include<iostream>
#include<memory>

class IButton{
    public:
    virtual void Clicked() = 0;
};

class WinButton: public IButton {
    public:
    void Clicked() override {
        std::cout << "Windows Button Clicked"<<std::endl;
    }
};

class UbuntuButton: public IButton {
    public:
    void Clicked() override {
        std::cout << "Ubuntu Button Clicked"<<std::endl;
    }
};

class IScrollBar{
    public:
    virtual void Scroll() = 0;
};

class WinScrollBar:public IScrollBar{
    public:
    void Scroll() override {
        std::cout << "Windows ScrollBar" <<std::endl; 
    }
};

class UbuntuScrollBar:public IScrollBar{
    public:
    void Scroll() override {
        std::cout << "Ubuntu ScrollBar"<<std::endl; 
    }
};

class IWidgetFactory {
    public:
    virtual std::unique_ptr<IButton> createButton() = 0;
    virtual std::unique_ptr<IScrollBar> createScrollBar() = 0;
};

class WinWidgetFactory: public IWidgetFactory {
    public:
    std::unique_ptr<IButton> createButton() override {
        return std::make_unique<WinButton>();
    }
    std::unique_ptr<IScrollBar> createScrollBar() override {
        return std::make_unique<WinScrollBar>();
    }
};

class UbuntuWidgetFactory: public IWidgetFactory {
    public:
    std::unique_ptr<IButton> createButton() override {
        return std::make_unique<UbuntuButton>();
    }
    std::unique_ptr<IScrollBar> createScrollBar() override {
        return std::make_unique<UbuntuScrollBar>();
    }
};

void operation(std::unique_ptr<IWidgetFactory> widget){
    std::unique_ptr<IButton> btn = nullptr;
    std::unique_ptr<IScrollBar> scroll = nullptr;
    btn = widget->createButton();
    scroll = widget->createScrollBar();
    btn->Clicked();
    scroll->Scroll();
}

int main() {
    /*
        Client Application uses IWidgetFactory abstract class
    */
    IWidgetFactory* widget = nullptr;
    operation(std::make_unique<UbuntuWidgetFactory>());
    operation(std::make_unique<WinWidgetFactory>());

    return 0;
}