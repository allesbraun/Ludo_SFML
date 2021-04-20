#include "Ludo.hpp"

Ludo::Ludo() : m_body(std::list<sf::Sprite>(4))
{
    m_head = --m_body.end();
    m_tail = m_body.begin();
}

Ludo::~Ludo()
{
}

void Ludo::Init(const sf::Texture &texture)
{
    float x = 16.f;
    for (auto &piece : m_body)
    {
        piece.setTexture(texture);
        piece.setPosition({x, 16.f});
        x += 16.f;
    }
}

void Ludo::Move(const sf::Vector2f &direction)
{
    m_tail->setPosition(m_head->getPosition() + direction);
    m_head = m_tail;
    ++m_tail;

    if (m_tail == m_body.end())
    {
        m_tail = m_body.begin();
    }
}

bool Ludo::IsOn(const sf::Sprite &other) const
{
    return other.getGlobalBounds().intersects(m_head->getGlobalBounds());
}

void Ludo::Grow(const sf::Vector2f &direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*(m_body.begin()->getTexture()));
    newPiece.setPosition(m_head->getPosition() + direction);

    m_head = m_body.insert(++m_head, newPiece);
}

bool Ludo::IsSelfIntersecting() const
{
    bool flag = false;

    for (auto piece = m_body.begin(); piece != m_body.end(); ++piece)
    {
        if (m_head != piece)
        {
            flag = IsOn(*piece);

            if (flag)
            {
                break;
            }
        }
    }

    return flag;
}

void Ludo::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &piece : m_body)
    {
        target.draw(piece);
    }
}