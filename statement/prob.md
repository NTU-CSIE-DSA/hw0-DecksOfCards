## Description

Given $n$ decks of cards, all initially empty, we want to perform four types of operations on them:

1. Add a card numbered $k$ to the top of deck $i$.
2. Remove the card from the top of deck $i$.
3. Move all cards from deck $i$ onto deck $j$.
4. Shuffle deck $i$ into deck $j$.

The shuffle operation merges two decks of cards according to the following procedure:

1. Move the top card from deck $i$ to the bottom of a temporary deck if deck $i$ isn't empty.
2. Move the top card from deck $j$ to the bottom of the temporary deck if deck $j$ isn't empty.
3. If one deck is empty, directly put the other deck to the bottom of the temporary deck. Otherwise, return to step 1.
4. Put the temporary deck back to deck $j$

After all operations, please output the cards in all decks.


## Input

The first line includes two integers, $N$ and $M$, representing the number of decks and operations.

The next $M$ lines include $2$ or $3$ integers. The first integer, $t$, represents the operation type:

- Type $1$ is for the "Add" operation, followed by two integers, $i$ and $k$, representing the target deck and the card number, respectively.
- Type $2$ is for the "Remove" operation, followed by only one integer, $i$, representing the target deck.
- Type $3$ is for the "Move" operation, followed by two integers, $i$ and $j$, representing the source and destination decks, respectively.
- Type $4$ is for the "Shuffle" operation, followed by two integers, $i$ and $j$, representing the source and destination decks, respectively.


## Output

The output should consist of $N$ lines.

For the $i$-th line, first output the number of cards in the $i$-th deck, denoted as $c_i$. Subsequently, output $c_i$ numbers representing the number of cards from top to bottom, with each number separated by spaces.


## Constraints

- $1\le N, M\le 10^5$
- $1\le i, j\le N$
- $1\le k\le 10^9$
- Guarantee that deck $i$ isn't empty when operation "Remove"
- Guarantee that deck $i$ isn't empty when operation "Remove"
- Guarantee that deck $i\neq j$ when operation "Move" and "Shuffle"

### Subtask 1 (20pts)

- $1 \leq N, M \leq 1000$

### Subtask 2 (10pts)

- Only "Add" and "Remove" operations

### Subtask 3 (20pts)

- Only "Add", "Remove", and "Move" operations

### Subtask 4 (50pts)

No other constraints


## Sample Testcases

### Sample Input 1

```
2 5
1 1 1
1 1 2
1 2 3
1 2 4
2 1
```

### Sample Output 1

```
1 1
2 4 3
```

### Sample Input 2

```
2 5
1 1 1
1 1 2
1 2 3
1 2 4
3 1 2
```

### Sample Output 2

```
0
4 2 1 4 3
```

### Sample Input 3

```
2 7
1 1 1
1 1 2
1 2 3
1 2 4
1 2 5
1 2 6
4 1 2
```

### Sample Output 3

```
0
6 2 6 1 5 4 3
```

## Hint

- http://140.113.150.142/problem/0/11258
- When doing "Shuffle," directly concatenate the deck behind the temporary deck when another deck is empty.
