#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>a[500005];
ll b[500005],ans[500005];
bool vis[500005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
       cin>>b[i];
        a[b[i]].push_back(i);
    }
    ll cou=0;
    ll n1=n;
    while(n1--){
            memset(vis,0,sizeof(vis));
        cou++;
        ll cnt=0;
        for(ll i=cou;i<=n;){
            ll au;
            for(int j=0;j<a[b[i]].size();j++){
                if(a[b[i]][j]==i)au=j;
            }
            if(au<a[b[i]].size()-1){
                i=a[b[i]][au+1];if(vis[b[i]]==0)ans[b[i]]++;
                vis[b[i]]=1;
            }
            else{
                if(vis[b[i]]==0)ans[b[i]]++;
                vis[b[i]]=1;i++;
            }
        }

    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
