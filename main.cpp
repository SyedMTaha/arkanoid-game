
////----------- ARKANOID GAME---------------///

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
using namespace sf;

struct Block {
    Sprite sprite;
    // Add any additional block-related information here
};

int main() {
    srand(time(0));

	//CREATING SCREEN FOR THE GAME
    RenderWindow app(VideoMode(520, 450), "Arkanoid!");
    app.setFramerateLimit(60);

	//IMAGES
    Texture t1, t2, t3, t4;
    t1.loadFromFile("block05.png");
    t2.loadFromFile("BG4.jpg");
    t3.loadFromFile("ball.png");
    t4.loadFromFile("paddle.png");

    Sprite sBackground(t2), sBall(t3), sPaddle(t4);
    sPaddle.setPosition(300, 440);

    std::list<Block> blocks;  // Linked list for blocks

    int n = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            Block block;
            block.sprite.setTexture(t1);
            block.sprite.setPosition(i * 43, j * 20);
            blocks.push_back(block);
            n++;
        }

    float dx = 6, dy = 5;
    float x = 300, y = 300;

    int score = 0;

    Font font;
    font.loadFromFile("arial.ttf");

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setColor(sf::Color::Black);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(10, 10);

    while (app.isOpen()) 
	{
        Event e;
        while (app.pollEvent(e)) 
		{
            if (e.type == Event::Closed)
                app.close();
        }

        x += dx;
        for (auto it = blocks.begin(); it != blocks.end();) 
		{
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(it->sprite.getGlobalBounds())) 
			{
                it = blocks.erase(it);
                dx = -dx;
                score += 10; // Increment the score (adjust the score value as needed)
            } else {
                ++it;
            }
        }

        y += dy;
        for (auto it = blocks.begin(); it != blocks.end();) 
		{
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(it->sprite.getGlobalBounds())) 
			{
                it = blocks.erase(it);
                dy = -dy;
                score += 10; // Increment the score (adjust the score value as needed)
            } else {
                ++it;
            }
        }

        if (blocks.empty()) 
		{
            // All blocks destroyed - End the game
            app.close();
        }

        if (x < 0 || x > 520)
            dx = -dx;
        if (y > 450) 
		{
            // Ball touched the ground - Game Over
            app.close();
        }
        if (y < 0)
            dy = -dy;
		//MOVEMENT OF THE PADDLE
		
        if (Keyboard::isKeyPressed(Keyboard::Right))
            sPaddle.move(12, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left))
            sPaddle.move(-12, 0);

        if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds()))
            dy = -(rand() % 5 + 2);

        sBall.setPosition(x, y);

        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);

        for (const auto& block : blocks)
            app.draw(block.sprite);

        // Update and draw the score
        scoreText.setString("Score: " + std::to_string(score));
        app.draw(scoreText);
        app.display();
    }

    return 0;
}




