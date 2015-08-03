#include "ButtonBase.hpp"

namespace gui
{
    ButtonBase::ButtonBase(std::string _label)
    {
        visible = true;
        hovering = false;
        wasHovering = false;

        sfColor.r      = sfColor.g      = sfColor.b      = 54;
        sfHoverColor.r = sfHoverColor.g = sfHoverColor.b = 70;
        sfTextColor.r  = sfTextColor.g  = sfTextColor.b  = 230;

        sfText.setString(_label);
        sfText.setCharacterSize(20);
        sfText.setColor(sfTextColor);
        sfText.setFont(sfFont);

        width = sfText.getLocalBounds().width + 12;
        height = 30;

        sfRect.setSize(sf::Vector2f(width, height));
        sfRect.setFillColor(sfColor);
    }
}
