#ifndef BUTTONBASE_H
#define BUTTONBASE_H

#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "functions.hpp"
#include "Widget.hpp"

namespace gui
{
    class ButtonBase : public Widget
    {
        friend class Gui;
        public:
            ButtonBase(std::string _label);
        protected:
            sf::RectangleShape sfRect;
            sf::Text sfText;
            sf::Color sfColor;
            sf::Color sfHoverColor;
            sf::Color sfTextColor;

            bool visible;
            bool hovering;
            bool wasHovering;
        private:
    };
}

#endif // BUTTONBASE_H
