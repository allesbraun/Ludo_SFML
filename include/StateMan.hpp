#ifndef STATEMAN_HPP
#define STATEMAN_HPP

#include "State.hpp"
#include <stack>
#include <memory>

namespace Engine{
    class StateMan{
        public:
            StateMan();//construtor
            ~StateMan();//destrutor

            void Add(std::unique_ptr<State> toAdd, bool replace = false);
            void PopCurrent();
            void ProcessStateChange();
            std::unique_ptr<State>& GetCurrent();
        private:
            std::stack<std::unique_ptr<State>> m_stateStack;
            std::unique_ptr<State> m_newState;
            /*State stack should only be modified at the start
            of the next update cycle*/
            bool m_add;
            bool m_replace;
            bool m_remove;
    };
}//namespace Engine

#endif