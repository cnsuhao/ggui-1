#include "Widget.hpp"

namespace gui
{
    Widget::Widget()
    {

    }

    bool Widget::update()
    {
        std::cout << "This widget has no update function!" << std::endl;
    }

    void Widget::draw()
    {
        std::cout << "This widget has no draw function!" << std::endl;
    }

    void Widget::updateValues()
    {
        std::cout << "This widget has no updateValues function!" << std::endl;
    }

    void Widget::handleEvent(sf::Event * _event)
    {

    }
}
