#include<bits/stdc++.h>
using namespace std;
deque<int> arr[100005];

int main(){
    int n,m,t;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d",&t);
        if(t==1){
            int id,k;
            scanf("%d%d",&id,&k);
            arr[id].push_front(k);
        }
        else if(t==2){
            int id;
            scanf("%d",&id);
            arr[id].pop_front();
        }
        else if(t==3){
            int src,des;
            scanf("%d%d",&src,&des);
            while(!arr[src].empty()){
               int tmp=arr[src].back();
               arr[src].pop_back();
               arr[des].push_front(tmp);
            }
        }
        else if(t==4){
            int src,des;
            scanf("%d%d",&src,&des);
            deque<int>tmp;
            while(!arr[src].empty()&&!arr[des].empty()){
               int tmp1=arr[src].front(),tmp2=arr[des].front();
               arr[src].pop_front();
               arr[des].pop_front();
               tmp.push_back(tmp1);
               tmp.push_back(tmp2);
            }
            while(!arr[src].empty()){
               int tmp1=arr[src].front();
               arr[src].pop_front();
               tmp.push_back(tmp1);
            }
            while(!arr[des].empty()){
               int tmp2=arr[des].front();
               arr[des].pop_front();
               tmp.push_back(tmp2);
            }
            while(!tmp.empty()){
                arr[des].push_back(tmp.front());
                tmp.pop_front();
            }
        }
        else{
            assert(0);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",(int)arr[i].size());
        while(!arr[i].empty()){
            int tmp=arr[i].front();
            arr[i].pop_front();
            printf("%d ",tmp);
        }
        printf("\n");
    }
}