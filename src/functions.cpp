#include "functions.hpp"

namespace gui
{
    sf::Font sfFont;

    static bool init()
    {
        sfFont.loadFromFile("ubuntu.ttf");
        return true;
    }

    bool ifInit = init();

    bool hover(int x1, int y1, int x2, int y2, sf::RenderWindow* window)
    {
        sf::Vector2i position = sf::Mouse::getPosition(*window);

        if (position.x >= x1 && position.y >= y1 && position.x <= x2 && position.y <= y2)
        {
            return true;
            window->setSize(sf::Vector2u(840, 480));
        }
        else
        {
            return false;
        }
    }

    bool click()
    {
        static bool shouldClick = true;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (shouldClick)
            {
                shouldClick = false;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            shouldClick = true;
            return false;
        }
    }
}
