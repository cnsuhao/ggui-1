# ggui

ggui is a graphical user interface library written in c++ with SFML. Right now it's very basic but more features will come over time.

## Example usage:

```cpp

#include "include/gui.hpp"

int main()
{   
    sf::RenderWindow window(sf::VideoMode(950, 600), "ggui works!");

    // Create the gui:
    gui::Gui gui1(&window);
    
    // Prevent lag
    window.setFramerateLimit(300); 
    
    // Create a button with label "Hello"
    gui::Button button1("Hello World!");
    
    // Add the button to the gui
    gui1.addWidget(&button1);
    
    // Draw the gui (First we clear the screen)
    window.clear();
    gui1.draw();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Send events to the gui
            gui1.handleEvent(&event);
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Update the gui
        gui1.update();
        
        window.display();
    }

    return 0;
}

```
