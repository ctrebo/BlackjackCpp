#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <array>

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

int generateIDforCard(deck_type& deck);
void printDeck(const deck_type& deck);
void shuffleDeck(deck_type& deck);
deck_type createDeck();

#endif // !DECK_H
