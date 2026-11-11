#include <bits/stdc++.h>
using namespace std;
int tong[300005],kapian[500005],table[500005],posi[500005];
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,finish;cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>kapian[i];
    for(int start=1;start<=n;start++){
        for(int i=start;i<=n;i++){
            finish=start;
            if(vis[table[finish]]=0){
                cin>>table[finish];
                vis[table[finish]]=1;
                posi[table[finish]]=finish;
                finish++;
            }
            else{
                cin>>table[posi[table[finish]]];
                for(int j=posi[table[finish]]+1;j<=finish;j++)
                    vis[table[finish]]=0;
                finish=posi[table[finish]]+1;
            }
        }
        for(int i=1;i<=finish;i++){
            tong[table[i]]++;
        }
    }
    for(int i=1;i<=300005;i++){
        if(tong[i]!=0)
            cout<<tong[i]<<" ";
    }
    return 0;
}
