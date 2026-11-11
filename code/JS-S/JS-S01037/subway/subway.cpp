#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+505;
int n,m,d,q,k,u,v,w;
long long a[N];
vector<pair<int,long long>> e[N];

int dis[N];
void dijk(int s){
    //cout << "IN\n";
    memset(dis,0x3f,sizeof dis);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(q.size()){
        auto tmp = q.top();
        int w = tmp.first,u = tmp.second;
        q.pop();
        if(w >= dis[u]) continue;
        //cerr << u << ' ' << w << endl;
        if(dis[u] > w){
            dis[u] = w;
        }
        for(auto [v,W]:e[u]){
            q.push({w+W,v});
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int n;
    cin >> n >> n>>m >> d >> q;
    for(int i = 1;i <= m;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        cin >> k;
        for(int j = 1;j <= k;j ++){
            cin >> v >> w;
            v += 501;
            e[i].push_back({v,w});
            e[v].push_back({i,w});
        }
    }
    for(int i = 1;i <= q;i ++){
        cin >> u >> v;
        dijk(u+501);
        cout << dis[v+501]+a[u]+a[v] << "\n";
    }
}
