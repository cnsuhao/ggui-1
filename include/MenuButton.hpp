#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <string>
#include <ButtonBase.hpp>

namespace gui
{
    class MenuButton : public ButtonBase
    {
        public:
            MenuButton(std::string _label);
        protected:
        private:
    };
}

#endif // MENUBUTTON_H
