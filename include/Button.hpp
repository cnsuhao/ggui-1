#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ButtonBase.hpp"
#include "functions.hpp"

namespace gui
{
    class Button: public ButtonBase
    {
        friend class Gui;
        public:
            Button(std::string _label);
            void addClickFunction(void (*_f)());
            bool update();
            void draw();
        private:
            void updateValues();
            void (*clickFunction)();
            bool clickCallback;
    };
}

#endif // BUTTON_H

/*
 
 rdfgdfögdfögldkfö
 
 */