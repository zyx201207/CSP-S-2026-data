#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int c,T,n,k,vs[N];
vector<int> g[N];
void clear(){
    for(int i=1;i<=n;++i)
        g[i].clear();
    
}
void dfs(int x,int dep){
    int y;
    
}
int main(){
     freopen("hub.in","r",stdin);
     freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        clear();
        cin>>n>>k;
        int x,y;
        for(int i=1;i<=n;++i){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    return 0;
}
