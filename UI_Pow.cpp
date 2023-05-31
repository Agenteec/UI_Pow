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

//void openWindow2(sf::RenderWindow &w) {
//    sf::Event event;
//    while (w.pollEvent(event))
//    {
//        if (event.type == sf::Event::Closed)
//        w.close();
//    }
//    w.clear(sf::Color::White);
//    w.display();
//}

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
        window.setFramerateLimit(60);

        // Инициализация IMGUI для SFML
        ImGui::SFML::Init(window);

        sf::Clock deltaClock;
        bool showMenu = true;
        bool createMassive = false;
        bool find = false;
        bool show = false;
        bool quit = false;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                ImGui::SFML::ProcessEvent(event);

                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            ImGui::SFML::Update(window, deltaClock.restart());

            // Создание интерфейса с помощью IMGUI
            ImGui::Begin("Menu");

            if (showMenu) {
                if (ImGui::Button("Create massive")) {
                    createMassive = true;
                    find = false;
                    show = false;
                    quit = false;
                }

                if (ImGui::Button("Find")) {
                    createMassive = false;
                    find = true;
                    show = false;
                    quit = false;
                }

                if (ImGui::Button("Show")) {
                    createMassive = false;
                    find = false;
                    show = true;
                    quit = false;
                }
                else {
                    // Запрещаем выбор команды "Show" после запуска приложения
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
                    ImGui::Button("Show");
                    ImGui::PopStyleVar();
                }

                if (ImGui::Button("Quit")) {
                    createMassive = false;
                    find = false;
                    show = false;
                    quit = true;
                }
            }
            else {
                ImGui::Text("Application closed");
            }

            ImGui::End();

            if (quit) {
                window.close();
            }

            window.clear();

            // Отрисовка интерфейса IMGUI
            ImGui::SFML::Render(window);

            window.display();
        }

        // Очистка ресурсов IMGUI
        ImGui::SFML::Shutdown();

        return 0;
    }