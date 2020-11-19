#ifndef CARD_H
#define CARD_H


enum class CardSuit {
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,

    MAX_SUITS
};

enum class CardRank {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANKS
};


struct Card {
    CardRank rank{};
    CardSuit suit{};
};

void printCard(const Card& card);
int getCardValue(const Card& card);

char standOrGo();

#endif
