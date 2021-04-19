#include "StateMan.hpp"

Engine::StateMan::StateMan():m_add(false), m_replace(false), m_remove(false){

}
Engine::StateMan::~StateMan(){}

void Engine::StateMan::Add(std::unique_ptr<State> toAdd, bool replace = false){
    m_add = true;
    m_newState = std::move(toAdd);
    m_replace = replace;
}
void Engine::StateMan::PopCurrent(){
    m_remove = true;

}
void Engine::StateMan::ProcessStateChange(){
    if(m_remove && (!m_stateStack.empty())){
        m_stateStack.pop();
    }

}
std::unique_ptr<Engine::State>& Engine::StateMan::GetCurrent(){
    m_stateStack.top();
}