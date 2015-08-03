#include "Gui.hpp"

namespace gui
{
    Gui::Gui(sf::RenderWindow * _renderWindow)
    {
        renderWindow = _renderWindow;
        x = 0;
        y = 0;
    }

    void Gui::draw()
    {
        for (int i = 0; i < widgets.size(); i++)
        {
            widgets[i]->draw();
        }
    }

    void Gui::update()
    {
        for (int i = 0; i < widgets.size(); i++)
        {
            widgets[i]->update();
        }
    }

    void Gui::handleEvent(sf::Event * _event)
    {
        for (int i = 0; i < widgets.size(); i++)
        {
            widgets[i]->handleEvent(_event);
        }

        if (_event->type == sf::Event::MouseButtonPressed)
        {
            for (int i = 0; i < widgets.size(); i++)
            {
                if (_event->mouseButton.x > widgets[i]->x && _event->mouseButton.x < widgets[i]->x + widgets[i]->width &&
                    _event->mouseButton.y > widgets[i]->y && _event->mouseButton.y < widgets[i]->y + widgets[i]->height)
                {
                    widgets[i]->active = true;
                }
                else
                {
                    widgets[i]->active = false;
                }


            }
        }
    }

    void Gui::addWidget(Widget * _widget)
    {
        widgets.push_back(_widget);
        _widget->renderWindow = renderWindow;

        int bx; // new button x value
        int by; // new button y value

        if (x + _widget->width <= renderWindow->getSize().x)
        {
            bx = x;
            by = y;
            x += _widget->width;
        }
        else
        {
            y += _widget->height;
            x =  _widget->width;
            bx = 0;
            by = y;
        }

        _widget->x = bx;
        _widget->y = by;
        _widget->updateValues();
    }


}
