// main.cpp
#include <SFML/Graphics.hpp>

int main() {
  // 1) VideoMode now takes a Vector2u, so we pass it via an initializer list
  sf::VideoMode mode{
      {800,
       600}}; // width=800, height=600 :contentReference[oaicite:0]{index=0}
  sf::RenderWindow window{mode, "Bouncy Ball", sf::Style::Close};
  window.setFramerateLimit(60);

  // 2) Create a circle of radius 20
  const float radius = 20.f;
  sf::CircleShape ball{radius};
  ball.setFillColor(sf::Color::Cyan);

  // 3) Position is now set via a single Vector2f argument
  ball.setPosition(
      {(window.getSize().x - 2 * radius) / 2.f,
       (window.getSize().y - 2 * radius) /
           2.f}); // setPosition(Vector2f) :contentReference[oaicite:1]{index=1}

  // 4) Initial velocity
  sf::Vector2f velocity{200.f, 150.f};

  sf::Clock clock;
  while (window.isOpen()) {
    // 5) pollEvent() returns std::optional<Event> now
    while (auto event =
               window.pollEvent()) // std::optional<Event> pollEvent()
                                   // :contentReference[oaicite:2]{index=2}
    {
      if (event->is<sf::Event::Closed>()) // use event->is<T>() rather than
                                          // evt.type
        window.close();
    }

    float dt = clock.restart().asSeconds();

    // 6) Move and bounce
    sf::Vector2f pos = ball.getPosition();
    pos += velocity * dt;

    if (pos.x <= 0.f) {
      pos.x = 0.f;
      velocity.x = -velocity.x;
    } else if (pos.x + 2 * radius >= window.getSize().x) {
      pos.x = window.getSize().x - 2 * radius;
      velocity.x = -velocity.x;
    }

    if (pos.y <= 0.f) {
      pos.y = 0.f;
      velocity.y = -velocity.y;
    } else if (pos.y + 2 * radius >= window.getSize().y) {
      pos.y = window.getSize().y - 2 * radius;
      velocity.y = -velocity.y;
    }

    ball.setPosition(pos);

    // 7) Draw
    window.clear(sf::Color::Black);
    window.draw(ball);
    window.display();
  }

  return 0;
}
