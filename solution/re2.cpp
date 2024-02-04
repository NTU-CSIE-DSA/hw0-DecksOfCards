#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct card {
  int num;
  struct card* nxt;
} Card;

Card *top[100001] = {}, *bottom[100001] = {};
int size[100001] = {};

void Add(int idx, int num) {
  Card *new_card = (Card*) malloc(sizeof(Card));
  new_card -> num = num;
  new_card -> nxt = top[idx];
  top[idx] = new_card;
  size[idx]++;
  if(size[idx] == 1) {
    bottom[idx] = new_card;
  }
}

void Remove(int idx) {
  Card *cur_top = top[idx];
  top[idx] = cur_top -> nxt;
  size[idx]--;
  if(size[idx] == 0) {
    bottom[idx] = NULL;
    top[idx] = NULL;
  }
  free(cur_top);
}

void Move(int idx1, int idx2) {
  if(top[idx1] != NULL) {
    bottom[idx1] -> nxt = top[idx2];
    top[idx2] = top[idx1];
    if(bottom[idx2] == NULL) {
      bottom[idx2] = bottom[idx1];
    }
  }
  size[idx2] += size[idx1];
  size[idx1] = 0;
}

void Shuffle(int idx1, int idx2) {
  Card *p1 = top[idx1], *p2 = top[idx2];
  Card *new_top = (p1)? p1: p2;
  Card *nxt_p1;
  Card *nxt_p2;
  while(p1 != NULL && p2 != NULL) {
    nxt_p1 = p1 -> nxt;
    nxt_p2 = p2 -> nxt;
    p1 -> nxt = p2;
    if(nxt_p1 != NULL) p2 -> nxt = nxt_p1;
    p1 = nxt_p1;
    p2 = nxt_p2;
  }
  if(p1 != NULL) {
    bottom[idx2] = bottom[idx1];
  }
  size[idx2] += size[idx1];
  size[idx1] = 0;
  top[idx2] = new_top;
  bottom[idx1] = NULL;
  top[idx1] = NULL;
}

int main() {

  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    int op;
    scanf("%d", &op);
    if(op == 1){
      int idx, num;
      scanf("%d%d", &idx, &num);
      Add(idx, num);
    }
    else if(op == 2) {
      int idx;
      scanf("%d", &idx);
      Remove(idx);
    }
    else if(op == 3) {
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

  for(int i = 1; i <= n; i++) {
    printf("%d ", size[i]);
    Card *p = top[i];
    while(p != NULL) {
      printf("%d ", p->num);
      p = p->nxt;
    }
    printf("\n");
  }

  return 0;
}
