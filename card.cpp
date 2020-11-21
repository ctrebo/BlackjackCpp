#include "card.h"
#include <iostream>

int generateIDforcard(const Card &deck) {
    static int i{ 0 };
    ++i;
    if (i == 51)
        i = 0;
    return i;
}

void printCard(const Card& card){
    switch (card.rank) {
    case CardRank::RANK_2:
        std::cout << '2';
        break;
    case CardRank::RANK_3:
        std::cout << '3';
        break;
    case CardRank::RANK_4:
        std::cout << '4';
        break;
    case CardRank::RANK_5:
        std::cout << '5';
        break;
    case CardRank::RANK_6:
        std::cout << '6';
        break;
    case CardRank::RANK_7:
        std::cout << '7';
        break;
    case CardRank::RANK_8:
        std::cout << '8';
        break;
    case CardRank::RANK_9:
        std::cout << '9';
        break;
    case CardRank::RANK_10:
        std::cout << 'T';
        break;
    case CardRank::RANK_JACK:
        std::cout << 'J';
        break;
    case CardRank::RANK_QUEEN:
        std::cout << 'Q';
        break;
    case CardRank::RANK_KING:
        std::cout << 'K';
        break;
    case CardRank::RANK_ACE:
        std::cout << 'A';
        break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suit) {
    case CardSuit::SUIT_CLUB:
        std::cout << 'C';
        break;
    case CardSuit::SUIT_DIAMOND:
        std::cout << 'D';
        break;
    case CardSuit::SUIT_HEART:
        std::cout << 'H';
        break;
    case CardSuit::SUIT_SPADE:
        std::cout << 'S';
        break;
    default:
        std::cout << '?';
        break;
    }
}

int getCardValue(const Card& card) {
    if (card.rank <= CardRank::RANK_10) {
        return (static_cast<int>(card.rank) + 2);
    }

    switch (card.rank) {
    case CardRank::RANK_JACK:
    case CardRank::RANK_KING:
    case CardRank::RANK_QUEEN:
        return 10;
        break;
    case CardRank::RANK_ACE:
        //could ask here if ace should be 1 or 11
        int value{};
        while (true) {
            std::cout << "Would you like to use your Ace as an 1 or 11?: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32656, '\n');
            }
            if (value == 1 || value == 11) {
                return value;
            }
        }
        break;
    }
}

bool getOptionforOtherCard() {
    std::cout << "Do you want another card?('y' or 'n'): ";
    char option{};
    std::cin >> option;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32343, '\n');
    }

    if (option == 'y') {
        return true;
    }
    else if (option == 'n') {
        return false;
    }

    return 0;
}