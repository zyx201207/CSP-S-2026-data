#include<bits/stdc++.h>
using namespace std;
int ans3[500005],bag[500005],n,m;
bool vis[500005];
int checkbag(int a,int l){
    for(int i=l;i<n;i++){
        if(bag[i]==a&&vis[i]==1)return i;
    }
    return -1;
}
void visbag(int l,int r,bool a){
    for(int i=l;i<r;i++){
        vis[i]=a;
    }
}
void andans(int l){
    for(int i=l;i<n;i++){
        if(vis[i]==1){
            ans3[bag[i]]++;
        }
    }
}
void bmp(int l){
    for(int i=l;i<n;i++){
        int a=checkbag(bag[i],l);
        if(vis[a]==1){
            visbag(a,i,0);
        }
    }
    andans(l);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>bag[i];
    }
    for(int i=0;i<n;i++){
        visbag(i,n+1,1);
        bmp(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans3[i]<<" ";
    }
    return 0;
}
