#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ci[550000];
ll zb[330000],cnt[330000];
void clear(){
    for(ll i=1;i<=320000;i++)zb[i]=0;
    return;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>ci[i];
    }
    for(ll i=1;i<=n;i++){
        clear();
        for(ll k=i;k<=n;k++){
            if(zb[ci[k]]!=0){
                for(ll p=zb[ci[k]];p<=k;p++){
                    zb[ci[p]]=0;
                }
            }
            zb[ci[k]]=k;
        }
        for(ll k=1;k<=m;k++){
            cnt[k]+=(zb[k]!=0);
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
