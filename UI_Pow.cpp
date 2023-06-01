#include <iostream>
#include <SFML/Graphics.hpp>
#define IMGUI_IMPL_OPENGL_LOADER_SFML
#include <imgui.h>
#include <imgui-SFML.h>
#include <thread>
#include "Tabs.h"
#include "BTNsf.h"

#pragma region SFMLFont
sf::Font font;
#pragma endregion

void ShowWindow(sf::RenderWindow &w) {
    sf::Event event;
    while (w.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        w.close();
    }
    w.clear(sf::Color::White);
    w.display();
}
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Марина Можаева ИС1-Б22 QT-GI-17");
    sf::RenderWindow tab(sf::VideoMode(1000, 900), L"Марина Можаева ИС1-Б22 QT-GI-17");
    //tab.close();
    tab.setVisible(false);
    if (!font.loadFromFile("Fonts\\arial.ttf"))
    {
        std::cout << "Unable to load font!\n";
        return EXIT_FAILURE;
    }
    ImGui::SFML::Init(window);

    bool createMassive = false;
    bool find = false;
    bool show = false;
    bool quit = false;
    int CBIndex = 0;
    const char* CBText[2] = {"Random","Test"};
    Tab t(font);
    t.Init();
    Text Pcount;
    Pcount.setFont(font);
    Pcount.setFillColor(Color(204,224,255));
    Pcount.setCharacterSize(16);
    Pcount.setPosition(Vector2f(630,40));
    Pcount.setString(L"Кол-во степеней:");
    bool isInit = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Event te;
        while (tab.pollEvent(te))
        {

            if (te.type == sf::Event::Closed)
                tab.setVisible(false);
            t.drawPow(tab,te);
        }


        ImGui::SFML::Update(window, sf::seconds(1.f / 60.f));
        // Создание главного окна imgui
        ImGui::SetNextWindowSizeConstraints(ImVec2(800,600), ImVec2(FLT_MAX, FLT_MAX));
        ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.25f);
        ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus);

        // Отрисовка кнопок
        ImGui::Dummy(ImVec2(10.0f, 10.f));
  
            if (ImGui::Combo(u8"Create massive",&CBIndex,CBText,2))
            {
                
                switch (CBIndex)
                {
                case 0:
                    t.Random_click();
                    isInit = 1;
                    break;
                case 1:
                    t.Test_click();
                    isInit = 1;
                    break;
                default:
                    break;
                }
            }
        ImGui::Spacing();
        ImGui::SameLine();
            if (ImGui::Button(u8"Find", ImVec2(200.f, 50.f)))
            {
                Pcount.setString(L"Кол - во степеней :" + std::to_string(t.Find_clicked()));
                isInit = 1;
            }
        //ImGui::Spacing();
        ImGui::SameLine();
        if (isInit)
            if (ImGui::Button(u8"Show", ImVec2(200.f, 50.f)))
            {
                tab.setVisible(true);
            }
        //ImGui::Spacing();
        ImGui::SameLine();
        if (ImGui::Button(u8"Quit", ImVec2(200.f, 50.f)))
        {
            window.close();
        }

        // Закрытие главного окна imgui
        ImGui::End();

        window.clear();
        tab.clear();

        ImGui::SFML::Render(window);
        t.draw(tab);
        tab.display();
        window.draw(Pcount);
        window.display();
    }

    ImGui::SFML::Shutdown();
    
    return 0;
}