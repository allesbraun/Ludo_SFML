#ifndef ASSETMAN_HPP
#define ASSETMAN_HPP

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine{
    class AssetMan{
        private:
            std::map<int, std::unique_ptr<sf::Texture>> m_textures;
            std::map<int, std::unique_ptr<sf::Font>> m_fonts;
        public:
            AssetMan();//construtor
            ~AssetMan();//destrutor
            //set
            void AddTexture(int id, const std::string &filePath, bool wantRepeated = false);
            void AddFont(int id, const std::string &filePath);
            //get
            const sf::Texture &GetTexture(int id) const;
            const sf::Font &GetFont(int id) const;
    };
}//namespace Engine

#endif