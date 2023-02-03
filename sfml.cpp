#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace sf;
using namespace std;

View view;

float offsetX = 0, offsetY = 0;

int count_money = 0;
int count_life = 3;
int n_kart = 4;

bool muz_vkl;

const int x_count = 5;
const int H = 23;
const int W = 160;

String TileMap[x_count][H] = {
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                               BBbbbbBBB                                                                                                        S      BBBBBBBB",
        "B       CMC                    BBBbbbbbBBB                                                                                                       T      BBBBBBBB",
        "BAA                            BBBbbbbbBBBB                                                                                              BB      T      BBBBBBBB",
        "B              BB         BB   BBBbbbbbBBBBB      AAA          BbbbbB                        BB BB          AMCCAC     CMA             BbBB      T      BBBBBBBB",
        "B    G        BBBB        BB   BBBbbbbbBBBBBB                 BBbbbbBB         G    G      BBBB BBBB                                 BBBbBB      T      BBBBBBBB",
        "B    T       BBBBBB       BB   BBBbbbbbBBBBBBB               BBBbbbbBBB        T    T    BBBBBB BBBBBB                             BBBBBbbb      P      BBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBbbbbbbBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBbbbbbBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                CCCCCC     CCCCCM                             AMA                                                                    BBBBBBBB",
        "B                                                                                                                                                 S   BBBBBBBB",
        "B                      CCCCCC                                                                                              BbbbbB                 T   BBBBBBBB",
        "B                                                                           CCAACAC                                      BBBbbbbBBB               T   BBBBBBBB",
        "B                                                C                                                                     BBBBBbbbbBBBBB             T   BBBBBBBB",
        "B                    G        G                             G   G        G           G               G    G          BBBBBBBbbbbBBBBBBB           T   BBBBBBBB",
        "B                    T        T                             T   T        T           T               T    T        BBBBBBBBBbbbbBBBBBBBBB         P   BBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBbbbbbBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBbbBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBBbbbbBBBBBBBBBBBBBBBBB   BBBBBBBBBB           BBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBbBBbbBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBBBbbBBBBBBBBBBBBBBBBBB   BBBBBBBBBB           BBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBbBBbbBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBB           BBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBbBBbbBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBB           BBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBbBBbbBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBB           BBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBbBBbbBBBBBBBBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                 M                                             M                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                CCCC                                 C      CCCC                       BBBBBBBB",
        "B                                                                                                       G   G                                           BBBBBBBB",
        "B                                                                                                       T   T                                           BBBBBBBB",
        "BMMC                                                             BBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB           BBBBBBBB",
        "B                                                               BBBBbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB           BBBBBBBB",
        "B                                                              BBBB                                                                                     BBBBBBBB",
        "B   C                                                         BBBB                                                                               S      BBBBBBBB",
        "B                             BbbbbBB                        BBBB                                                                      B         T      BBBBBBBB",
        "B                            BB    BBB                      BBB                                                                       BB         T      BBBBBBBB",
        "BCCCC                       BBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBB                                    CCC                               BBB         T      BBBBBBBB",
        "B                          BBBB      BBB                           G   G                       G             G                      BBBB         T      BBBBBBBB",
        "B                         BBBBB      BBB                           T   T                       T             T                     BBBBB         P      BBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    0000    BBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                   MC                                                  BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                          CM                           BBBBBBBB",
        "B                                              CCCC                  CCCCCCCCCCC  CCCC            CCCC                                                  BBBBBBBB",
        "B                                                                   CC                    CCCC                                                          BBBBBBBB",
        "B                                CMCC                              CCC                                   CCCC           CCCCCCCC                        BBBBBBBB",
        "B                                            G      G                                                                                                   BBBBBBBB",
        "B                                            T      T                                                                                                   BBBBBBBB",
        "B                             BBBBBBBBBBBBBBBBbbbbbbBBBBBBBBBBBBBBBBBBbbbbbbbbbbbBBBBBBBBBbbbbBBBbbBBBbBBbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB       S      BBBBBBBB",
        "B                                                                                                                                                T      BBBBBBBB",
        "B                          B                                                                                                                     T      BBBBBBBB",
        "B                         BB                                                                                                      B              T      BBBBBBBB",
        "B           G    G       BBB                  G    G                  G   CCCC   G                                               BB              T      BBBBBBBB",
        "B           T    T      BBBB                  T    T                  T          T                                              BBB              P      BBBBBBBB",
        "BBBBBBBBBBBBB    BBBBBBBBBBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBB          BBBBBBBBBBbbbbBBBBBBBBBBBbbbBBBBBBBBBBBBBBBBBBBBBBBBBBbbbbBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBB    BBBBBBBBBBBBBBBBB  BBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBB          BBBBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBB          BBBBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBB          BBBBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBB          BBBBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBB          BBBBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBb    BBBBBBBBBBBBBBBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                                                                                       BBBBBBBB",
        "B                                                                                           bB                                                          BBBBBBBB",
        "B                                                                                           bB                                                          BBBBBBBB",
        "B                                                                                           bB                                                          BBBBBBBB",
        "B                                                                                           bB                                                          BBBBBBBB",
        "B                                                                                           bB                               BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "B                                                                               BBBBBBBBBBBBbB                                                          BBBBBBBB",
        "B                                                                              BB           bB                                                   S      BBBBBBBB", 
        "B                                                                             BB            bB                              BbbBBBBBBBBBBBBBBBBBBB      BBBBBBBB",
        "B                                                                            BB      B      bB                             BBbbBBBBBBBBBBBBBBBBBBB      BBBBBBBB",
        "B                                                                           BB     BBB      bB                            BBBbbBBBBBBBBBBBBBBBBBBB      BBBBBBBB",
        "B                g    g                            B                                        bB                           BBBBbbBBBBBBBBBBBBBBBBBBB      BBBBBBBB",
        "B                t    t                           Bc                                        bB                          BBBBBbbBBBBBBBBBBBBBBBBBBB      BBBBBBBB",
        "BBBBBBBBBBBBBBBBBB    BbBBBBBBBBBBBBBBBBBBBBBBBBBBCbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBB    BbBBBBBBBBBBBBBBBBBBBBBBBBBBCbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBB    BbBBBBBBBBBBBBBBBBBBBBBBBBBBCbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbBBBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBB    BbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBB    BbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBB    BbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBbbBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};

bool start_menu(RenderWindow & window) {
    Font font;
    font.loadFromFile("hrifta/norm/static/InterTight-ExtraBold.ttf");

    Text text_vkl_off("", font, 30);
    text_vkl_off.setFillColor(Color::Black);
    text_vkl_off.setStyle(Text::Italic);
    text_vkl_off.setString("Turn I for vkl off music");
    text_vkl_off.setPosition(view.getCenter().x - 375, 
    view.getCenter().y - 250);//задаем позицию текста, отступая от центра камеры

    Text text_vkl_on("", font, 30);
    text_vkl_on.setFillColor(Color::Black);
    text_vkl_on.setStyle(Text::Italic);
    text_vkl_on.setString("Turn O for vkl on music");
    text_vkl_on.setPosition(view.getCenter().x - 375, view.getCenter().y - 250);//задаем позицию текста, отступая от центра камеры



    Texture menuFone, menuStart, menuOn, menuOff;
    menuOn.loadFromFile("kartinki/of.png");
    menuOff.loadFromFile("kartinki/on.png");
    menuFone.loadFromFile("kartinki/phone.png");
    //menuStart.loadFromFile("kartinki/");
    Sprite menuFe(menuFone), menuSt(menuStart), soundOn(menuOn), soundOff(menuOff);
    menuFe.setPosition(0, 0);
    soundOn.setPosition(200, 150);
    soundOff.setPosition(200, 150);
    
    bool isMenu = 1;
    int Muz = 0;
    while (isMenu) {
        window.clear(Color(129, 181, 221));

        if (Keyboard::isKeyPressed(Keyboard::Return)) isMenu = false;
        if (Keyboard::isKeyPressed(Keyboard::I) and Muz == 1) Muz = 0;
        if (Keyboard::isKeyPressed(Keyboard::O) and Muz == 0) Muz = 1;

        window.draw(menuFe);
        if (Muz == 1) { window.draw(text_vkl_off); window.draw(soundOn); }
        if (Muz == 0) { window.draw(text_vkl_on); window.draw(soundOff); }
        window.display();
    }

    if (Muz == 1) return true;
    else return false;
}

void game_horoh(RenderWindow & window) {
    Texture menuTexture3, menuBackground;
    menuTexture3.loadFromFile("kartinki/exit.png");
    menuBackground.loadFromFile("kartinki/konec_horoh.jpg");
    Sprite menu3(menuTexture3), menuBg(menuBackground);
    bool isMenu = 1;
    menu3.setPosition(100, 150);
    menuBg.setPosition(0, 0);

    //////////////////////////////МЕНЮ///////////////////
    while (isMenu) {
        menu3.setColor(Color::White);
        window.clear(Color(129, 181, 221));

        if (Keyboard::isKeyPressed(Keyboard::Return)) isMenu = false;

        window.draw(menuBg);
        window.draw(menu3);

        window.display();
    }
    ////////////////////////////////////////////////////

}

void game_level(RenderWindow & window, int level) {
    Font font;
    font.loadFromFile("hrifta/norm/static/InterTight-ExtraBold.ttf");
    Text text_nachat("", font, 30);
    text_nachat.setFillColor(Color::White);
    text_nachat.setStyle(Text::Regular);

    Text podz("", font, 30);
    podz.setFillColor(Color::White);
    podz.setStyle(Text::Regular);
    podz.setPosition(view.getCenter().x - 375, view.getCenter().y - 250);

    Text text_level("", font, 30);
    text_level.setFillColor(Color::Red);
    text_level.setStyle(Text::Italic);

    text_level.setString("Next Level: " + to_string(level+1));
    text_level.setPosition(view.getCenter().x - 300, view.getCenter().y - 400);//задаем позицию текста, отступая от центра камеры

    text_nachat.setString("Press return for contunie");
    text_nachat.setPosition(view.getCenter().x - 375, 
    view.getCenter().y - 350);//задаем позицию текста, отступая от центра камеры

    Texture menuBackground;
	menuBackground.loadFromFile("kartinki/phone_menu.jpeg");
	Sprite menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menuBg.setPosition(0, 0);
 
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu) {
		menuNum = 0;
		window.clear(Color(129, 181, 221));
 
		if (Keyboard::isKeyPressed(Keyboard::Return)) isMenu = false;//если нажали первую кнопку, то выходим из меню 
		
        window.draw(menuBg);
        if (level >= 4) window.draw(podz);
        window.draw(text_level);
        window.draw(text_nachat);
		window.display();
	}
    
}

void game_over(RenderWindow & window) {
    
    Texture menuTexture3, menuBackground;
    menuTexture3.loadFromFile("kartinki/exit.png");
    menuBackground.loadFromFile("kartinki/ajyt.png");
    Sprite menu3(menuTexture3), menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    menu3.setPosition(100, 150);
    menuBg.setPosition(0, 0);


    //////////////////////////////МЕНЮ///////////////////
    while (isMenu) {
        menu3.setColor(Color::White);
        window.clear(Color(129, 181, 221));

        if (Keyboard::isKeyPressed(Keyboard::Return)) isMenu = false;

        window.draw(menuBg);
        window.draw(menu3);

        window.display();
    }
    ////////////////////////////////////////////////////

}

class PLAYER {

public:

    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;

    PLAYER(Texture& image) {
        sprite.setTexture(image);
        rect = FloatRect(220, 482, 30, 60);

        dx = dy = 0.1;
        currentFrame = 0;
    }

    void xydate(int x, int y) {
        rect.left = rect.top = 200;
    }

    void update(float time) {

        rect.left += dx * time;
        Collision(0);

        if (!onGround) dy = dy + 0.0005 * time;
        rect.top += dy * time;
        onGround = false;
        Collision(1);

        currentFrame += 0.0075 * time;
        if (currentFrame > 4) currentFrame -= 4;

        if (dx > 0) sprite.setTextureRect(IntRect(35 * int(currentFrame), 0, 30, 60));
        if (dx < 0) sprite.setTextureRect(IntRect(35 * int(currentFrame), 65, 30, 60));


        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
        dx = 0;
    }

    void Collision(int dir) {
        for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
            for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
                if (TileMap[n_kart][i][j] == 'B' or TileMap[n_kart][i][j] == 'C' or TileMap[n_kart][i][j] == 'T' or TileMap[n_kart][i][j] == 'G' or TileMap[n_kart][i][j] == 'S' or TileMap[n_kart][i][j] == 'P') {
                    if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
                    if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;  onGround = true; }
                    if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
                }

                if (TileMap[n_kart][i][j] == 'M') {
                    if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
                    if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0; onGround = true; }
                    if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32; dy = 0; TileMap[n_kart][i][j] = 'C';  TileMap[n_kart][i-1][j] = '0'; }
                }

                if (TileMap[n_kart][i][j] == 'A') {
                    if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
                    if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0; onGround = true; }
                    if ((dy < 0) && (dir == 1)) { TileMap[n_kart][i][j] = ' '; rect.top = i * 32 + 32; dy = 0; }
                }

                if (TileMap[n_kart][i][j] == 'O') {
                    count_money++; TileMap[n_kart][i][j] = ' ';
                }

                if (TileMap[n_kart][i][j] == 'H') {
                    count_life++; TileMap[n_kart][i][j] = ' '; 
                }

            }

    }
};

class Koroleva {
public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    float currentFrame;
    bool onGround;

    void set(Texture &image, int x, int y) {
        sprite.setTexture(image);
        rect = FloatRect(x, y, 20, 32);

        dx = 0.05;
        currentFrame = 0;
    }

    void update(float time) {
        Collision(0);

        if (!onGround) {
            dy = dy + 0.0005 * time;
            rect.top += dy * time;
            onGround = false;
        }


        Collision(1);

        currentFrame += 0.005;


        sprite.setTextureRect(IntRect(229, 158, -20, 22));

        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
    }

    void Collision(int dir) {
        for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
            for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
                if (TileMap[n_kart][i][j] == 'M' or TileMap[n_kart][i][j] == 'O' or TileMap[n_kart][i][j] == 'H' or TileMap[n_kart][i][j] == 'B' or TileMap[n_kart][i][j] == 'C' or TileMap[n_kart][i][j] == 'T' or TileMap[n_kart][i][j] == 'G' or TileMap[n_kart][i][j] == 'S' or TileMap[n_kart][i][j] == 'P') {
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;  onGround = true; }
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height; dy = 0; }
                }
            }
    }


};

class Enemy {
public:
float dx, dy;
FloatRect rect;
Sprite sprite;
float currentFrame;
bool life;
bool inStena;
bool onGround;

    void set(Texture &image, int x, int y) {
        sprite.setTexture(image);
        rect = FloatRect(x, y, 20, 32);

        inStena = false;
        dx = 0.05;
        currentFrame = 0;
        life = true;
    }

    void update(float time) {
        Collision(0);

        rect.left += 2 * dx * time;

        if (!onGround) {
            dy = dy + 0.0005 * time;
            rect.top += dy * time;
            onGround = false;
        }


        Collision(1);

        currentFrame += 0.005;
        if (currentFrame > 4) currentFrame -= 4;

        if (dx > 0) sprite.setTextureRect(IntRect(30 * int(currentFrame), 32, 20, 32));
        if (!life) sprite.setTextureRect(IntRect(7, 70, 20, 22));

        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
    }

    void Collision(int dir) {
        for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
            for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
                if (TileMap[n_kart][i][j] == 'M' or TileMap[n_kart][i][j] == 'O' or TileMap[n_kart][i][j] == 'H' or TileMap[n_kart][i][j] == 'B' or TileMap[n_kart][i][j] == 'C' or TileMap[n_kart][i][j] == 'T' or TileMap[n_kart][i][j] == 'G' or TileMap[n_kart][i][j] == 'S' or TileMap[n_kart][i][j] == 'P') {
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;  onGround = true; }
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height; dy = 0; }
                }
            }
    }

};


int main() {
    RenderWindow window(VideoMode(600 , 400), "! Mario-Test !");

    Texture t;
    t.loadFromFile("kartinki/mario.png");

    Font font;
    font.loadFromFile("hrifta/new/arial.ttf");
    Text text_money("", font, 25);
    text_money.setFillColor(Color::Yellow);
    text_money.setStyle(Text::Bold);

    Text text_life("", font, 25);
    text_life.setFillColor(Color::White);
    text_life.setStyle(Text::Bold);

    Text text_spasibo("", font, 35);
    text_spasibo.setFillColor(Color::Red);
    text_spasibo.setStyle(Text::Bold);

    Texture amogus;
    amogus.loadFromFile("kartinki/newimposter.png");

    Texture kostum;
    kostum.loadFromFile("kartinki/newimposter.png");

    Enemy enemy;
    enemy.set(amogus, 50, 28);

    Koroleva koroleva;
    koroleva.set(amogus, 4600, 100);

    PLAYER mario(t);
    float currentFrame = 0;

    Clock clock;

    Image map_image;
    //map_image.loadFromFile("kartinki/chel.png");
    map_image.loadFromFile("kartinki/poputka.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);

    Image fone_image;
    fone_image.loadFromFile("kartinki/elk.jpeg");
    //fone_image.loadFromFile("kartinki/hon.png");
    //fone_image.loadFromFile("kartinki/draiv.jpeg");
    fone_image.createMaskFromColor(fone_image.getPixel(0, 0));

    Texture fone_texture;
    fone_texture.loadFromImage(fone_image);
    Sprite fon_sprite;
    fon_sprite.setTexture(fone_texture);

    RectangleShape rectangle(Vector2f(32, 32));

    Music music;
    music.openFromFile("muzon/lo-fi_music.ogg");

    SoundBuffer shootBuffer;
    shootBuffer.loadFromFile("sound/newjump.ogg");
    Sound shoot(shootBuffer);

    SoundBuffer xrustBuffer;
    xrustBuffer.loadFromFile("sound/newxrust.ogg");
    Sound xrust(xrustBuffer);

    bool prohod = true;
    bool okno_zakruto = true;
    bool menu = 1;

    while (count_life > 0 and n_kart < x_count and okno_zakruto) {
        while (window.isOpen() and count_life > 0 and prohod) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();

            time = time / 700;

            if (time > 20) time = 20;

            Event event;
            while (window.pollEvent(event)) { if (event.type == Event::Closed) { okno_zakruto = false; window.close(); } }
            if (menu) { muz_vkl = start_menu(window); menu = 0; if (muz_vkl) { music.play(); music.setLoop(true); } }

            if (offsetX < 4300) {
                if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) mario.dx = -0.1;
                if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) mario.dx = 0.1;
                if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
                    if (mario.onGround) {
                        mario.dy = -0.35;
                        mario.onGround = false;
                        if (muz_vkl) shoot.play();
                    }
                }
            }

            mario.update(time);
            if (n_kart == 4) enemy.update(time);
            if (n_kart == 4) koroleva.update(time);

            if (mario.rect.intersects(enemy.rect)) {
                if (enemy.life) {
                    if (mario.dy > 0) {
                        enemy.dx = 0;
                        mario.dy = -0.2;
                        enemy.life = false;
                    }
                    else {
                        count_life--;
                        mario.rect.left = mario.rect.top = 200;
                    }
                }
            }

            if (mario.rect.left > 300) offsetX = mario.rect.left - 300;
            offsetY = mario.rect.top - 200;

            window.clear(Color::White);
            window.draw(fon_sprite);

            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++) {
                    if (TileMap[n_kart][i][j] == 'B') s_map.setTextureRect(IntRect(96, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'C') s_map.setTextureRect(IntRect(32, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'M') s_map.setTextureRect(IntRect(64, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'T') s_map.setTextureRect(IntRect(128, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'G') s_map.setTextureRect(IntRect(160, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'S') s_map.setTextureRect(IntRect(192, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'P') s_map.setTextureRect(IntRect(224, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'A') s_map.setTextureRect(IntRect(288, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'O') s_map.setTextureRect(IntRect(0, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == 'H') s_map.setTextureRect(IntRect(256, 0, 32, 32));
                    if (TileMap[n_kart][i][j] == ' ') continue;
                    if (TileMap[n_kart][i][j] == '0') {
                        if (muz_vkl) xrust.play();
                        if (count_life >= 3) {
                            TileMap[n_kart][i][j] = 'O';
                            s_map.setTextureRect(IntRect(0, 0, 32, 32));
                        }
                        else {
                            int k = rand();
                            if (k % 2 == 0) {
                                TileMap[n_kart][i][j] = 'O';
                                s_map.setTextureRect(IntRect(0, 0, 32, 32));
                            } else {
                                TileMap[n_kart][i][j] = 'H';
                                s_map.setTextureRect(IntRect(256, 0, 32, 32));
                            }
                        }
                    }

                    s_map.setPosition(j * 32 - offsetX, i * 32 - offsetY);
                    window.draw(s_map);
                }

            text_money.setString("Count money * " + to_string(count_money));
            text_money.setPosition(view.getCenter().x - 180,
                                   view.getCenter().y - 485);//задаем позицию текста, отступая от центра камеры

            text_life.setString("Count life * " + to_string(count_life));
            text_life.setPosition(view.getCenter().x - 450,
                                  view.getCenter().y - 485);//задаем позицию текста, отступая от центра камеры

            /*text_spasibo.setString("!!!Bro spasibo!!!");
            text_spasibo.setPosition(view.getCenter().x - 325, view.getCenter().y - 350);//задаем позицию текста, отступая от центра камеры

            if (offsetX >= 4300 and n_kart == 4) window.draw(text_spasibo);*/
            
            window.draw(text_money);
            window.draw(text_life);
            if (n_kart == 4) window.draw(enemy.sprite);
            window.draw(mario.sprite);
            if (n_kart == 4)  window.draw(koroleva.sprite);
            window.display();
            if (offsetY > 400) {
                count_life -= 1;
                mario.rect.left = 200;
                mario.rect.top = 200;
                offsetY = offsetX = 200;
            }
            if (offsetX >= 4300) {
                prohod = false;
                mario.rect.left = mario.rect.top = offsetY = offsetX = 200;
                enemy.life = true;
            }

        }
        prohod = true;
        n_kart++;

        if (okno_zakruto and count_life > 0 and n_kart < 5)  game_level(window, n_kart);

    }

    if (muz_vkl) music.stop();

    if (count_life <= 0 and okno_zakruto) game_over(window);
    if (count_life > 0 and okno_zakruto) game_horoh(window);

    return 0;
}