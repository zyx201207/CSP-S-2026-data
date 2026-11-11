#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+5,inf=1e9+7;
int c,t,n;
vector<int>adj[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        cout<<0<<"\n";
    }
    return 0;
}
