#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow Window(sf::VideoMode(1280, 720), "My program");
    Window.setFramerateLimit(60);

    sf::RectangleShape rect;
    sf::Vector2f rectanglePosition(600, 350);
    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(100, 100));

    sf::CircleShape circle;
    sf::Vector2f circlePosition(300, 200);
    circle.setPosition(circlePosition);
    circle.setRadius(50);

    float xCircle = 5;
    float yCircle = 5;

    float xVelocity = 3;
    float yVelocity = 3;

    while (Window.isOpen())
    {
        sf::Event event;
        while(Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) Window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Window.close();
        }
        if(rectanglePosition.x < 0 || rectanglePosition.x >1280 - 100) xVelocity *= -1;
        if(rectanglePosition.y < 0 || rectanglePosition.y >720 - 100) yVelocity *= -1;

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;
        rect.setPosition(rectanglePosition);

        if(circlePosition.x < 0 || circlePosition.x > 1280 - 100) xCircle *= -1;
        if(circlePosition.y < 0 || circlePosition.y> 720 - 100) yCircle *= -1;

        circlePosition.x += xCircle;
        circlePosition.y += yCircle;
        circle.setPosition(circlePosition);


         Window.clear();
         Window.draw(rect);
         Window.draw(circle);
         Window.display();
    }



    return 0;
}

