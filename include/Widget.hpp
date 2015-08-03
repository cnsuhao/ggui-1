#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace gui
{
    class Widget
    {
        friend class Gui;
        public:
            Widget();
            virtual bool update(); // Returns if the whole gui should be redrawn
            virtual void draw();
            virtual void handleEvent(sf::Event * _event);
        protected:
            sf::RenderWindow * renderWindow;
            sf::Event        * event;
            int x;
            int y;
            int width;
            int height;
            bool active;
            bool wasActive;

            virtual void updateValues();
        private:
    };
}

#endif // WIDGET_H
