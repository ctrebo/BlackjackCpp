#include "deck.h"
#include "card.h"

#include <iostream>
#include <array>
#include <ctime>
#include <random>


int generateIDforCard(deck_type& deck) {
    static int i{ 0 };
    ++i;
    if (i == 51) {
        i = 0;
        shuffleDeck(deck);
    }
    return i;
}

deck_type createDeck() {
    deck_type deck{};

    // We could initialize each card individually, but that would be a pain.  Let's use a loop.

    index_type card{ 0 };

    auto suits{ static_cast<int>(CardSuit::MAX_SUITS) };
    auto ranks{ static_cast<int>(CardRank::MAX_RANKS) };

    for (int suit{ 0 }; suit < suits; ++suit) {
        for (int rank{ 0 }; rank < ranks; ++rank) {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }

    return deck;
}

//function that prints deck
void printDeck(const deck_type& deck) {
    for (const auto& card : deck) {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

//fucntion that shuffles deck
void shuffleDeck(deck_type& deck) {
    // mt is static so it only gets seeded once.
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(deck.begin(), deck.end(), mt);
}