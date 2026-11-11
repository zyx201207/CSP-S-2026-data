#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int>> g[5005][5005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c, t;cin>>c>>t;
    while(t--){
        int n, k;cin>>n>>k;
        for(int i = 1; i<=n-1; i ++){
            int u, v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << abs(u-v)<<'\n';//?
    }
    return 0;
}
