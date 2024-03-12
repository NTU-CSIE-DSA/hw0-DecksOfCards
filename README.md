# DSA 2024 HW0 Problem 3 - Deck of Cards

## Tutorial
In the **Hint** Section, we suggested using a linked list to solve this problem. Specifically, a singly linked list suffices for this problem.

### Node
For each linked list node, we record two variables: an integer `num` representing the number on the card, and a pointer `nxt`, referencing the card below.

To ensure recognizability, We name this structure `Card`.

### Initialize
We declare three arrays: `Card` array `top` and `bottom` to record the top and the bottom cards of each deck, and an integer array `size` to record the number of cards for each deck. All of these variable's size is $10^5+1$, initially set `top` and `bottom` to `NULL`, and set `size` to `0`.

### Add
For this operation, we malloc a new `Card`, assign its `num` and reference its `nxt` to the top of this deck. We then update the top of this deck to point to this card and then increment the `size` by 1.

If this deck was empty, modify the bottom to this card.

The time complexity of this operation is $O(1)$, and the extra space of complexity this operation is $O(1)$.

### Remove
For this operation, we update the top of this deck to its `nxt` and then decrement the size by 1.

If this deck is empty after remove, modify the top and bottom to `NULL`.

To prevent memory waste, it's advisable to free this `Card`.

The time complexity of this operation is $O(1)$, and the extra space of complexity this operation is $O(1)$.

### Move
For this operation, we follow these steps: (Move the `idx1`-th deck onto `idx2`-th deck)
1. If the `idx1`-th deck is empty, nothing happens.
2. Otherwise, we set the `nxt` of bottom of the `idx1`-th deck to point to the top of the `idx2`-th deck, and then the top of the `idx2`-th deck becomes the top of the `idx1`-th deck.
3. If the `idx2`-th deck was empty, the bottom of the `idx2`-th deck becomes the bottom of the `idx1`-th deck.
4. Update the size of the `idx2`-th deck accordingly.
5. Since the `idx1`-th deck is now empty, modify both the top and bottom pointers to `NULL` and set its size to `0`.
The time complexity of this operation is $O(1)$, and the extra space of complexity this operation is $O(1)$.

### Shuffle

For this operation, we create a temporary deck and use two pointers, `p1` and `p2`, to reference cards in the two decks, and two pointers, `new_p1` and `new_p2`, to reference the next cards so that we can iterate through the decks easily.

Then, the top of the temporary deck will be set to `p1` if the idx-1-th deck is not empty; otherwise, it will be set to `p2`.

We now commence the "Shuffle" process. We repeat this loop until either `p1` and `p2` becomes `NULL`.
1. Set `nxt_p1` and `nxt_p2` to the next of `p1` and the next of `p2`.
2. Set `p1 -> nxt` to `p2`
3. If `nxt_p1` is not NULL, set `p2` to `nxt_p1`.
4. Set `p1` and `p2` to `nxt_p1` and `nxt_p2`.

For the remaining card in the larger deck, If there are remaining cards in the `idx1`-th deck, update the bottom of the `idx2`-th deck, then update the size and top of the `idx2`-th deck after merging.

Since the `idx1`-th deck is now empty, we follow the last step in **Move**.

The summation of the time complexity of this operation is $O(M)$ since we only spend time on the smaller deck (referred to as the "small to large" method, which you'll learn about in the Disjoint Set lecture this semester), and the extra space complexity of this operation is $O(1)$.

### Output
For output, simply print the size of each deck and iterate through each deck using pointers.

## Sample Code

```C
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each card in the deck
typedef struct Card {
  int num;            // Record the number on the card
  struct Card* nxt;   // Pointer to the below card
} Card;

Card *top[100001] = {}, *bottom[100001] = {};  // Record the top card and the bottom card for each deck
int size[100001] = {};  // Record the number of cards for each deck

// Type 1 operation: Add num to the idx-th deck
void Add(int idx, int num) {
  Card *new_card = (Card*) malloc(sizeof(Card));
  new_card -> num = num;
  new_card -> nxt = top[idx];
  top[idx] = new_card;
  size[idx]++;
  if (size[idx] == 1) {
    // If the idx-th deck was empty, modify the bottom
    bottom[idx] = new_card;
  }
}

// Type 2 operation: Remove a card from the idx-th deck
void Remove(int idx) {
  Card *cur_top = top[idx];
  // Modify the top card of idx-th deck
  top[idx] = cur_top -> nxt;
  size[idx]--;
  if (size[idx] == 0) {
    // If the idx-th deck is empty, modify the top and bottom to NULL
    bottom[idx] = NULL;
    top[idx] = NULL;
  }
  free(cur_top);
}

// Type 3 operation: Move the idx1-th deck onto the idx2-th deck
void Move(int idx1, int idx2) {
  if (top[idx1] == NULL) return;  // Nothing happens if the idx1-th deck is empty
  bottom[idx1] -> nxt = top[idx2];
  top[idx2] = top[idx1];
  if (bottom[idx2] == NULL) {
    bottom[idx2] = bottom[idx1];
  }
  size[idx2] += size[idx1];
  // The idx1-th deck is empty, modify the top and bottom to NULL
  top[idx1] = NULL;
  bottom[idx1] = NULL;
  size[idx1] = 0;
}

// Type 4 operation: Merge the idx1-th deck into the idx2-th deck
void Shuffle(int idx1, int idx2) {
  Card *p1 = top[idx1], *p2 = top[idx2];
  Card *new_top = (p1) ? p1 : p2;
  Card *nxt_p1, *nxt_p2;
  
  while (p1 != NULL && p2 != NULL) {
    // move the top card of the idx1-th deck and the idx2-th deck to the temporary deck
    // p1: the top of the idx1-th deck now
    // p2: the top of the idx2-th deck now
    nxt_p1 = p1 -> nxt;
    nxt_p2 = p2 -> nxt;
    p1 -> nxt = p2;
    if (nxt_p1 != NULL) p2 -> nxt = nxt_p1;
    p1 = nxt_p1;
    p2 = nxt_p2;
  }
  
  // If there are remaining cards in the idx1-th deck, update the bottom of the idx2-th deck
  if (p1 != NULL) {
    bottom[idx2] = bottom[idx1];
  }
  
  // Update the size and top of the idx2-th deck after merging
  size[idx2] += size[idx1];
  top[idx2] = new_top;
  
  // The idx1-th deck is empty, modify the top and bottom to NULL
  bottom[idx1] = NULL;
  top[idx1] = NULL;
  size[idx1] = 0;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int idx, num;
      scanf("%d%d", &idx, &num);
      Add(idx, num);
    } 
    else if (op == 2) {
      int idx;
      scanf("%d", &idx);
      Remove(idx);
    } 
    else if (op == 3) {
      int idx1, idx2;
      scanf("%d%d", &idx1, &idx2);
      Move(idx1, idx2);
    } 
    else {
      int idx1, idx2;
      scanf("%d%d", &idx1, &idx2);
      Shuffle(idx1, idx2);
    }
  }

  // Print the final state of each deck
  for (int i = 1; i <= n; i++) {
    printf("%d ", size[i]);
    Card *p = top[i];
    while (p != NULL) {
      printf("%d ", p -> num);
      p = p -> nxt;
    }
    printf("\n");
  }

  return 0;
}
```

## Coding Tips

Using pointers indeed simplifies the code. However, if you're not familiar with pointers, you can use a "pseudo-pointer" approach: 
- Declare enough amounts of Card structures as an array and use the index as the pointer to the next card.
