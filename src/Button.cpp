#include "Button.hpp"

namespace gui
{
    Button::Button(std::string _label): ButtonBase(_label)
    {
        clickCallback = false;
    }

    void Button::addClickFunction(void (*_f)())
    {
        clickFunction = _f;
        clickCallback = true;
    }

    bool Button::update()
    {
        int x      = sfRect.getPosition().x;
        int y      = sfRect.getPosition().y;
        int width  = sfRect.getSize().x;
        int height = sfRect.getSize().y;

        if (hover(x, y, x + width, y + height, renderWindow))
        {
            hovering = true;
            if (click() && clickCallback)
            {
                clickFunction();
            }
            if (!wasHovering)
            {
                wasHovering = true;
                draw();
                return false;
            }
        }
        else
        {
            hovering = false;
            if (wasHovering)
            {
                wasHovering = false;
                draw();
                return false;
            }
        }
    }

    void Button::updateValues()
    {
        sfRect.setPosition(sf::Vector2f(x, y));
        sfText.setPosition(sf::Vector2f(x + 5, y + 1));
    }

    void Button::draw()
    {
        if (hovering)
        {
            sfRect.setFillColor(sfHoverColor);
        }
        else
        {
            sfRect.setFillColor(sfColor);
        }

        renderWindow->draw(sfRect);
        renderWindow->draw(sfText);
    }
}
