#include <SFML/Graphics.hpp>
#include <time.h>

int main()
{
    //init
    int i;
    const int n = 20;
    int radius[n];
    float speedX[n];
    float speedY[n];
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My Program");
    window.setFramerateLimit(100);

    sf::CircleShape circ[n];
    srand(time(0));
    sf::Vector2f pos[n];

    //init value
    for (i = 0; i < n; i++) {
        speedX[i] = rand() % 10 + 1;
        speedY[i] = rand() % 10 + 1;
        pos[i].x = rand() % 900 + 100;
        pos[i].y = rand() % 600 + 100;

        circ[i].setPosition(pos[i]);
        radius[i] = rand() % 50;
        printf("%d: radius: %d\n", i + 1, radius[i]);
        circ[i].setRadius(radius[i]);
    }

    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }


        window.clear();
        for (i = 0; i < n; i++) {
            if (pos[i].x < 0 || pos[i].x > 1000 - radius[i]) 
                speedX[i] *= -1;
            if (pos[i].y < 0 || pos[i].y > 750 - radius[i]) 
                speedY[i] *= -1;
            pos[i].x += speedX[i];
            pos[i].y += speedY[i];
            circ[i].setPosition(pos[i]);
            window.draw(circ[i]);
        }
        window.display();

    }



    return 0;
}