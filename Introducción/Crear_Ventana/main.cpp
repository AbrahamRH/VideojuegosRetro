#include <SFML/Graphics.hpp> // Incluimos la biblioteca gráfica

int main()
{
    // Creamos nuestra ventana y la configuramos
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Ventana con circulo", sf::Style::Titlebar | sf::Style::Close);

    // Creamos una forma de circulo de radio de 250u de color rojo
    sf::CircleShape shape(500.f);
    shape.setFillColor(sf::Color::Red);

    // Cargamos la fuente que utilizaremos
    sf::Font font;
    if (!font.loadFromFile("04B_30__.TTF"))
        return EXIT_FAILURE;

    // Creamos un texto
    sf::Text text("Hello World",font,50);
    text.setFillColor(sf::Color::Green);
    text.setPosition(300,499);


    /* Otra forma de crear la ventana
     * sf::Text text;
     * text.setFont(font);
     * text.setString("Hello World");
     * text.setCharacterSize(50);
     */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Si se activa el evento de cerrar la pantalla terminamos con el bucle
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // En cada bucle se limpia la pantalla y se vuelve a dibujar la forma
        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}
