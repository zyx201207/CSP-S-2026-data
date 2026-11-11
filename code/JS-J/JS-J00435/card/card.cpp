#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],bd[500005];
ll k=0,ans[500005];
ll vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];

    for(ll js=1;js<=n;js++){
        memset(bd,0,sizeof(bd));
        memset(vis,0,sizeof(vis));
        for(ll i=js;i<=n;i++){
            if(vis[a[i]]==0)vis[a[i]]=++k,bd[k]=a[i];
            else{
                for(ll v=vis[a[i]]+1;v<=k;v++) vis[bd[v]]=0,bd[v]=0;
                k=vis[a[i]];
            }
        }
        for(ll v=1;v<=m;v++)if(vis[v])ans[v]++;
    }


    for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
