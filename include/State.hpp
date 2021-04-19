#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/System/Time.hpp>

namespace Engine{
    class State{
        public:
            State(){};//construtor
            virtual ~State(){};//destrutor
            
            virtual void Init() = 0;
            virtual void Process_Input() = 0;
            virtual void Update(sf::Time deltaTime) = 0;//fps
            virtual void Draw() = 0;

            virtual void Start(){}
            virtual void Pause(){}
    };
}//namespace Engine

#endif
