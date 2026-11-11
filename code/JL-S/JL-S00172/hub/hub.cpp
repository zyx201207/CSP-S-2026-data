#include<bits/stdc++.h>
using namespace std;
vector<int>mp[10005];
int popcount(int x){
    int ans = 0;
    while(x){
        if(x%2)ans++;
        x/=2;
    }
    return ans;
}
int x;
int n,k;
int dfs(int u,int f){
    if((x>>(u-1))&1)return 0;
    int mi = 1e9;
    for(auto v:mp[u])if(v!=f){
        mi=min(mi,dfs(v,u));
    }
    return mi+1;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int C,T;
    cin >> C >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++)mp[i].clear();
        for(int i = 1; i < n; i++){
            int u,v;
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int ans=1e9;
        for(int i = 0; i < (1<<n);i++){
            if(popcount(i)>k)continue;
            x=i;
            int mx = 0;
            for(int j = 1; j <= n; j++){
                mx=max(mx,dfs(j,0));
            }
            ans=min(ans,mx);
        }
        cout << ans<<'\n';
    }
    return 0;
}