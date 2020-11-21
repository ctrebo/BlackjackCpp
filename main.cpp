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

    score_dealer += getCardValue(deck[generateIDforCard(deck)]);
    score_player += getCardValue(deck[generateIDforCard(deck)]) + getCardValue(deck[generateIDforCard(deck)]);

    std::cout << "You got a total card value of " << score_player << '\n';
    bool option{ getOptionforOtherCard() };
    while (option) {
        score_player += getCardValue(deck[generateIDforCard(deck)]);
        std::cout << "You got a total card value of " << score_player << '\n';
        if (score_player > 21) {
            std::cout << "Lost" << '\n';
            return false;
        }
        option = getOptionforOtherCard();
    }
    std::cout << "You got a final card value of " << score_player << '\n';

    std::cout << "Now is the dealers turn!\n";
    score_dealer += getCardValue(deck[generateIDforCard(deck)]);
    std::cout << "The dealer has a hand value of " << score_dealer;
    while (score_dealer <= 17) {
        score_dealer += getCardValue(deck[generateIDforCard(deck)]);
        std::cout << "The dealer has a hand value of " << score_dealer;
        if (score_dealer > 21) {
            return true;
        }
    }
    if (score_player < score_dealer)
        return false;
    else if (score_player > score_dealer)
        return false;
    else if (score_player > score_dealer)
        return false;
    


}

int main()
{
     auto deck{ createDeck() };
     shuffleDeck(deck);

     bool whoWon{ playBlackjack(deck) };



     return 0;
}