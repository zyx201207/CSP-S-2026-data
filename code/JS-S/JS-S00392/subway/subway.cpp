/*g++ subway.cpp -o subway -std=c++14 -Wall -Wextra -fsanitize=undefined,address*/
//g++ subway.cpp -o subway -std=c++14 -static -O2
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e5+10, mod = 998244353;
int c,n,m,d,qry;
struct Node{
    int to;
    ll tim;//linefrom, lineto, time
};
vector <Node> G[(int)1.1e7+10];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qry;
    //cout<<qry<<endl;
    vector <ll> w(m+10,0);
    vector <int> k(n+10,0);
    for(int i = 1; i <= m; i++){
        cin>>w[i];
    }
    //cout<<w[m]<<endl;
    for(int i = 1; i <= n; i++){
        cin>>k[i];//the ith line
        int lst = -1;
        for(int j = 1; j <= k[i]; j++){
            int v;ll t;
            cin>>v>>t;
            G[v].emplace_back((Node){m*i+v, t});
            G[m*i+v].emplace_back((Node){v, t});
            if(j > 1){
                G[m*i+v].emplace_back((Node){m*i+lst,0});
                G[m*i+lst].emplace_back((Node){m*i+v,0});
                lst = v;
            }
        }
        //cout<<k[i]<<endl;
    }
    while(qry--){
        int beg, target;
        cin>>beg>>target;
        vector <bool> vis(m*(n+2)+10,0);
        vector <ll> dis(m*(n+2)+10,(ll)4e18);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> q;
        dis[beg] = 0;
        q.push({0ll,beg});
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            int u = cur.second;
            vis[u] = 1;
            for(auto tar : G[u]){
                int v = tar.to;
                if(!vis[v] && dis[u] + tar.tim < dis[v]){
                    dis[v] = dis[u] + tar.tim;
                    q.push({dis[v],v});
                }
            }
        }
        cout<<dis[target] + w[beg] + w[target]<<endl;
    }
    return 0;
}