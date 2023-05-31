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

//int main()
//{
//
//    if (!font.loadFromFile("Fonts\\arial.ttf"))
//    {
//        std::cout << "Unable to load font!\n";
//        return EXIT_FAILURE;
//    }
//    sf::RenderWindow window1(sf::VideoMode(800, 600), L"UI Pow");
//    sf::RenderWindow window2(sf::VideoMode(800, 600), L"Tab");
//    Button ShovTab(80,35);
//    ShovTab.setPosition(sf::Vector2f(100,100));
//    ShovTab.setFont(font);
//
//    while (window1.isOpen())
//    {
//
//        sf::Event event;
//        while (window1.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window1.close();
//        }
//        openWindow2(window2);
//        
//
//        // Обновление и отрисовка содержимого окон
//        window1.clear(sf::Color::White);
//        #pragma region UI
//        ShovTab.draw(window1);
//        #pragma endregion
//        window1.display();
//    }
//
//    return 0;
//}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Марина Можаева ИС1-Б22 QT-GI-17");
    //sf::RenderWindow tab(sf::VideoMode(800, 600), L"Марина Можаева ИС1-Б22 QT-GI-17");

    ImGui::SFML::Init(window);

    bool createMassive = false;
    bool find = false;
    bool show = false;
    bool quit = false;
    int CBIndex = 0;
    const char* CBText[2] = {"Random","Test"};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
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

                //showLocalGame = true;
            }
        ImGui::Spacing();
        ImGui::SameLine();
            if (ImGui::Button(u8"Find", ImVec2(200.f, 50.f)))
            {
                //showNetworkGame = true;
            }
        //ImGui::Spacing();
        ImGui::SameLine();
        if (1)
            if (ImGui::Button(u8"Show", ImVec2(200.f, 50.f)))
            {

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

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}