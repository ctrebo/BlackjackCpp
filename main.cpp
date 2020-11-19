#include "card.h"
#include "deck.h"

#include <iostream>
#include <iterator> // for std::size
#include <string>
#include <algorithm>
#include <cstddef> // std::size_t
#include <string_view>
#include <array>
#include <vector>
#include <numeric> // std::reduce
#include <ctime>
#include <random>
#include <cstdlib>



bool playBlackjack(deck_type& deck) {
    int score_player{ 0 };
    int score_dealer{ 0 };

    score_dealer += getCardValue(deck[0]);
    score_player += getCardValue(deck[1]) + getCardValue(deck[2]);

    bool get_another_card{ true };
    while (get_another_card) {

    }

    return 0;
}

int main()
{
     auto deck{ createDeck() };
     shuffleDeck(deck);
     printDeck(deck);
     return 0;
}