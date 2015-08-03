#include "Input.hpp"

namespace gui
{
    Input::Input(int _width)
    {
        width = _width;
        height = 26;
        writeCursorBlinkTime = 0;
        writeCursorBlink = true;
        active = false;

        sfColor       = sf::Color::White;
        sfBorderColor.r = sfBorderColor.g = sfBorderColor.b = 200;
        sfBorderActiveColor = sf::Color::Blue;
        sfTextColor   = sf::Color::Black;

        sfRect.setSize(sf::Vector2f(width, height));
        sfRect.setFillColor(sfColor);
        sfRect.setOutlineColor(sfBorderColor);
        sfRect.setOutlineThickness(2);

        sf::Text temp;
        temp.setCharacterSize(25);
        temp.setColor(sfTextColor);
        temp.setFont(sfFont);
        temp.setString("|");
        temp.setPosition(sf::Vector2f(x, y));
        sfLetters.push_back(temp);
    }

    void Input::updateValues()
    {
        sfRect.setPosition(x, y + 2);
    }

    bool Input::update()
    {
        if (active)
        {
            if (!wasActive)
            {
                wasActive = true;
                sfRect.setOutlineColor(sfBorderActiveColor);
                draw();
            }
            writeCursorBlinkTime++;
            if (writeCursorBlinkTime > 150)
            {
                writeCursorBlinkTime = 0;
                writeCursorBlink ^= 1; // Inverts the boolean
                draw();
            }
        }
        else
        {
            if (wasActive)
            {
                wasActive = false;
                sfRect.setOutlineColor(sfBorderColor);
                writeCursorBlink = false;
                draw();
            }
        }

        return false;
    }

    void Input::draw()
    {
        renderWindow->draw(sfRect);

        int tempX = 0;
        for (int i = 0; i < sfLetters.size(); i++)
        {
            if (i == sfLetters.size() - 1)
            {
                sfLetters[i].setPosition(sf::Vector2f(x + tempX, y - 3));
                if (writeCursorBlink)
                    renderWindow->draw(sfLetters[i]);
            }
            else
            {
                sfLetters[i].setPosition(sf::Vector2f(x + tempX, y - 2));
                renderWindow->draw(sfLetters[i]);
            }

            tempX += sfLetters[i].getLocalBounds().width + 2;
        }
    }

    void Input::handleEvent(sf::Event * _event)
    {
        if (active)
        {
            if (_event->type == sf::Event::TextEntered)
            {
                int pos = sfLetters.size() - 1;

                if (_event->text.unicode == 8)
                {
                    if (pos >= 1)
                    {
                        sfLetters.erase(sfLetters.begin() + pos - 1);
                    }
                }
                else
                {
                    sf::Text temp;

                    temp.setCharacterSize(25);
                    temp.setColor(sfTextColor);
                    temp.setFont(sfFont);

                    temp.setString(static_cast<char>(_event->text.unicode));

                    sfLetters.insert(sfLetters.begin() + pos, temp);
                }

                inputValue = "";
                for (int i = 0; i < sfLetters.size(); i++)
                {
                    if (i != sfLetters.size() - 1)
                        inputValue += sfLetters[i].getString();
                }

                std::cout << inputValue << std::endl;

                draw();
            }
        }
    }

}
