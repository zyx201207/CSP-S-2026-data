#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,ans,ansp;
ll n,m;
vector<ll> v[100005];
void dfs(ll x,ll fa,ll dep){
    for(auto i:v[x]){
        if(i==fa) continue;
        if(dep+1>ans){
            ans=dep+1;
            ansp=i;
        }
        dfs(i,x,dep+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0,0);
        dfs(ansp,0,0);
        cout<<ans/(m+1);
    }
    return 0;
}
