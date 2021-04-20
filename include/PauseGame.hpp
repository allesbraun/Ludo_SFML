#ifndef PAUSEGAME_HPP
#define PAUSEGAME_HPP

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class PauseGame : public Engine::State{
    private:
        std::shared_ptr<Context> m_context;
        sf::Text m_pauseTitle;

    public:
        PauseGame(std::shared_ptr<Context> &context);
        ~PauseGame();

        void Init() override;
        void Process_Input() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
};

#endif
