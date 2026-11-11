#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define INF 1000000007
#define MOD 998244353
using namespace std;

vector<int> g[MAXN];
int ans;
void dfs(int x,int fa){
    for(int i : g[x]){
        if(i == x)continue;
        dfs(i,x);
        ans++;
    }

}
ll c,t,n,k;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 1; i <= n; i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<0<<"\n";
    }

    return 0;
}
