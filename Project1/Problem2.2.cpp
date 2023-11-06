#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

void drawShape(int, int, double, int);
void drawGraph();

int initialx = -20;
int initialy = -20;
double initialradius = 50;

int scale = 4;

int windowsize = 720;

sf::RenderWindow window(sf::VideoMode(windowsize, windowsize), "Problem 2.2");
sf::CircleShape circle;

int main()
{
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Transparent);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        drawGraph();
        //because of how the draw function in this library works my x axis needs to be inverse, function is effectively drawShape(x,y,radius)
        drawShape(-initialx * scale, initialy * scale, initialradius * scale, 0);
        window.display();
    }
    return 0;
}
void drawShape(int x, int y, double radius, int colorincrement) {
    circle.setOrigin(x - (windowsize / 2 - radius), y - (windowsize / 2 - radius));
    //the draw function in this iteration defaults the origin of the circle to be in the top left corner, exactly 1 radius length away from the top and left sides,
    //so we subtract that from length of window to offset the circle to the correct position for the origin
    //function is effectively origin = (x,y)
    circle.setRadius(radius);
    circle.setOutlineColor(sf::Color(0, 25 + 25 * colorincrement, 0));
    window.draw(circle);
    int newx = x - 6 * scale;
    //because of how the draw function in this library works my x axis needs to be inverse, function is effectively x2=x1+6
    int newy = y + 6 * scale;
    int newradius = radius - 5*scale;
    if (newradius >= 5 * scale) {
        drawShape(newx, newy, newradius, colorincrement + 1);
    }
    return;
}

//This entire function below only serves to create the layout of the graph and the axises for the image

void drawGraph() {
    sf::RectangleShape xaxis(sf::Vector2f(windowsize, 1));
    sf::RectangleShape yaxis(sf::Vector2f(1, windowsize));
    sf::RectangleShape graph(sf::Vector2f(windowsize * 0.8, windowsize * 0.8));
    graph.setOutlineThickness(2);
    graph.setOutlineColor(sf::Color::Black);
    graph.setFillColor(sf::Color::Transparent);
    graph.setOrigin(-(windowsize / 2 - windowsize * 0.4), -(windowsize / 2 - windowsize * 0.4));
    xaxis.setOrigin(0, -windowsize / 2);
    yaxis.setOrigin(-windowsize / 2, 0);
    xaxis.setFillColor(sf::Color::Black);
    yaxis.setFillColor(sf::Color::Black);
    window.draw(graph);
    window.draw(xaxis);
    window.draw(yaxis);

    sf::RectangleShape line1(sf::Vector2f(1, scale * 5));
    sf::RectangleShape line2(sf::Vector2f(1, scale * 5));
    sf::RectangleShape line3(sf::Vector2f(1, scale * 5));
    sf::RectangleShape line4(sf::Vector2f(1, scale * 5));
    line1.setOrigin(-1 * windowsize / 6, -windowsize * 0.9);
    line2.setOrigin(-2 * windowsize / 6, -windowsize * 0.9);
    line3.setOrigin(-4 * windowsize / 6, -windowsize * 0.9);
    line4.setOrigin(-5 * windowsize / 6, -windowsize * 0.9);

    sf::RectangleShape line5(sf::Vector2f(scale * 5, 1));
    sf::RectangleShape line6(sf::Vector2f(scale * 5, 1));
    sf::RectangleShape line7(sf::Vector2f(scale * 5, 1));
    sf::RectangleShape line8(sf::Vector2f(scale * 5, 1));
    line5.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4), -1 * windowsize / 6);
    line6.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4), -2 * windowsize / 6);
    line7.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4), -4 * windowsize / 6);
    line8.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4), -5 * windowsize / 6);

    line1.setFillColor(sf::Color::Black);
    line2.setFillColor(sf::Color::Black);
    line3.setFillColor(sf::Color::Black);
    line4.setFillColor(sf::Color::Black);
    line5.setFillColor(sf::Color::Black);
    line6.setFillColor(sf::Color::Black);
    line7.setFillColor(sf::Color::Black);
    line8.setFillColor(sf::Color::Black);
    window.draw(line1);
    window.draw(line2);
    window.draw(line3);
    window.draw(line4);
    window.draw(line5);
    window.draw(line6);
    window.draw(line7);
    window.draw(line8);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text1(to_string(-2 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text2(to_string(-1 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text3(to_string(1 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text4(to_string(2 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text5(to_string(2 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text6(to_string(1 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text7(to_string(-1 * windowsize / (6 * scale)), font, 5 * scale);
    sf::Text text8(to_string(-2 * windowsize / (6 * scale)), font, 5 * scale);
    text1.setOrigin(-1 * windowsize / 6 + 10 / 3 * scale, -windowsize * 0.9 - 4 * scale);
    text2.setOrigin(-2 * windowsize / 6 + 10 / 3 * scale, -windowsize * 0.9 - 4 * scale);
    text3.setOrigin(-4 * windowsize / 6 + 5 / 2 * scale, -windowsize * 0.9 - 4 * scale);
    text4.setOrigin(-5 * windowsize / 6 + 5 / 2 * scale, -windowsize * 0.9 - 4 * scale);
    text5.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4) + 6 * scale, -1 * windowsize / 6 + 2.5 * scale);
    text6.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4) + 6 * scale, -2 * windowsize / 6 + 2.5 * scale);
    text7.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4) + 8 * scale, -4 * windowsize / 6 + 2.5 * scale);
    text8.setOrigin(scale * 5 - (windowsize / 2 - windowsize * 0.4) + 8 * scale, -5 * windowsize / 6 + 2.5 * scale);
    text1.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);
    text3.setFillColor(sf::Color::Black);
    text4.setFillColor(sf::Color::Black);
    text5.setFillColor(sf::Color::Black);
    text6.setFillColor(sf::Color::Black);
    text7.setFillColor(sf::Color::Black);
    text8.setFillColor(sf::Color::Black);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.draw(text5);
    window.draw(text6);
    window.draw(text7);
    window.draw(text8);
}