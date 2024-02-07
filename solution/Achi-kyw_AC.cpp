#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node{
    int num;
    struct node *next;
}node;

typedef struct deck{
    node *top,*bottom;
    int size;
}deck;

deck d[100005];

int main(){
    int n,m,t;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)d[i].top=d[i].bottom=NULL;
    while(m--){
        scanf("%d",&t);
        if(t==1){
            int id,k;
            scanf("%d%d",&id,&k);
            node *new_card=(node *)malloc(sizeof(node));
            new_card->num=k;
            new_card->next=d[id].top;
            d[id].top=new_card;
            if(d[id].size==0){
                d[id].bottom=new_card;
            }
            d[id].size++;
        }
        else if(t==2){
            int id,k;
            scanf("%d",&id);
            //intentionally do not free
            d[id].top=d[id].top->next;
            if(d[id].size==1){
                d[id].bottom=d[id].top=NULL;
            }
            d[id].size--;
        }
        else if(t==3){
            int src,des;
            scanf("%d%d",&src,&des);
            if(d[src].top!=NULL){
                d[src].bottom->next=d[des].top;
                d[des].top=d[src].top;
                if(d[des].bottom==NULL)d[des].bottom=d[src].bottom;
                d[src].top=d[src].bottom=NULL;
                d[des].size+=d[src].size;
                d[src].size=0;
            }
        }
        else if(t==4){
            int src,des;
            scanf("%d%d",&src,&des);
            node *cur1=d[src].top,*cur2=d[des].top,*tmpcur1,*tmpcur2;
            deck tmp;
            if(d[src].size==0)tmp.top=cur2;
            else tmp.top=cur1;
            while(cur1!=NULL&&cur2!=NULL){
                tmpcur1=cur1->next;
                tmpcur2=cur2->next;
                cur1->next=cur2;
                if(tmpcur1!=NULL)cur2->next=tmpcur1;
                cur1=tmpcur1;
                cur2=tmpcur2;
            }
            tmp.bottom=(cur1==NULL?d[des].bottom:d[src].bottom);
            tmp.size=d[src].size+d[des].size;
            d[src].top=d[src].bottom=NULL;
            d[src].size=0;
            d[des]=tmp;
        }
        else{
            assert(0);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",d[i].size);
        for(node *it=d[i].top;it!=NULL;it=it->next){
            printf("%d ",it->num);
        }
        printf("\n");
    }
}