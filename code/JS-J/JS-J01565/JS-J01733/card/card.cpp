#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int vis[500005],cnt[500005],vis1[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                for(int k=vis1[a[j]]+1;k<=n;k++){
                    vis[k]=0;
                }
            }
            else{
                vis[a[j]]=1;
                vis1[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j]==1)cnt[j]++;
        }
    }
   for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
