#ifndef GUI_H
#define GUI_H

#include <vector>
#include <SFML/Window.hpp>
#include "ButtonBase.hpp"
#include "Button.hpp"
#include "Input.hpp"
#include "Widget.hpp"

namespace gui
{
    class Gui
    {
        public:
            Gui(sf::RenderWindow * _renderWindow);
            void draw();
            void update();
            void handleEvent(sf::Event * _event);

            void addWidget(Widget * _widget);
        private:
            sf::RenderWindow * renderWindow;

            std::vector<Widget*> widgets;

            int x;
            int y;
    };
}

#endif // GUI_H
