#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "functions.hpp"
#include "Widget.hpp"

namespace gui
{
    class Input : public Widget
    {
        friend class Gui;
        public:
            Input(int _width);
            bool update(); // Returns if the whole gui should be redrawn
            void draw();
            void handleEvent(sf::Event * _event);
            void updateValues();
            std::string inputValue;
        private:
            std::vector<sf::Text> sfLetters;
            sf::RectangleShape sfRect;
            sf::RectangleShape sfTextCursor;
            sf::Color          sfColor;
            sf::Color          sfBorderColor;
            sf::Color          sfBorderActiveColor;
            sf::Color          sfTextColor;

            int writeCursorBlinkTime;
            bool writeCursorBlink;
    };
}

#endif // INPUT_H
