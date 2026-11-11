#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> g[1000005];
int solve(){
    cin>>n>>k;
    for(int i = 1;i < n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return 0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
    return 0;
}
