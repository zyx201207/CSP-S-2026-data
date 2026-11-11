#include<bits/stdc++.h>
using namespace std;
int n,m;
int car[500005],vis[300005],dui[500005],cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>car[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[j]=0;
        }
        for(int i=1;i<=n;i++) dui[i]=0;
        int cur=1;
        for(int j=i;j<=n;j++){
            if(vis[car[j]]){
                for(int k=vis[car[j]]+1;k<cur;k++){
                    vis[dui[k]]=0;
                    dui[k]=0;
                }
                cur=vis[car[j]];
            }else{
                dui[cur]=car[j];
                vis[car[j]]=cur;
            }
            cur++;
        }
        for(int j=1;j<=m;j++){
            if(vis[j]) cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
