#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll f[500005];
ll vis[300005];
ll ans[300005];
bool s[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
        vis[f[i]]++;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            if(vis[f[j]]>1){
                for(ll k=j-1;k>=i;k--){
                    if(f[k]==f[j]&&s[k]==0){
                        for(ll t=k;t<j;t++){
                            s[t]=1;
                        }
                        break;
                    }
                }
            }
        }
        for(ll j=i;j<=n;j++){
            if(s[j]==0){
                ans[f[j]]++;
            }
            s[j]=0;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
