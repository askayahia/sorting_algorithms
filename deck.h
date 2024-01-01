#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>



/**
 * enum kind_e - kind Card
 * @SPADE: spade
 * @HEART: heart
 * @CLUB: clubs
 * @DIAMOND: diamond.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - playing card
 *
 * @value: value of the card
 * From "Ace" to "King"
 * @kind: kind of the card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - deck of card
 *
 * @card: Pointer to card of the node.
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of list!
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int my_value_card(deck_node_t *node);
int my_strcamp(const char *my_1, const char *my_2);
size_t my_len_deck(deck_node_t *list);

#endif
