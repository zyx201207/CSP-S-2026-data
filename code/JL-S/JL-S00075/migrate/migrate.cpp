#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
vector <ll> e[N];
ll vis[N];
ll a[N];
ll ans,minv;
ll c,t;
ll n,d;
void dfs(ll x,ll ed,ll step){
    vis[x]=1;
    if(step>minv)
        return;
    if(x==ed){
        if(step==minv)
            ans++;
        else if(step<minv){
            minv=step;
            ans=1;
        }
        return;
    }
    for(auto u:e[x]){
        if(!vis[u]){
            dfs(u,ed,step+1);
            vis[u]=0;
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        for(ll i=1;i<=n;i++)
            e[i].clear();
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])<=d){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        ll res=0;
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                memset(vis,0,sizeof(vis));
                minv=INT_MAX;
                ans=0;
                dfs(i,j,1);
                if(ans==2)
                    res++;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
