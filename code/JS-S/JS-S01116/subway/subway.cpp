#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
const int inf = 0x3f3f3f3f;

int read(){
    int x = 0,f = 1;char c = getchar_unlocked();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar_unlocked();}
    while(isdigit(c)){x = x*10 + c-'0';c = getchar_unlocked();}
    return x*f;
}

struct node{
    int id,val;
    bool operator <(node T)const{
        return val < T.val;
    }
};

int n,m,d,p,c,cnt;
vector<node>g[4*N];

map<int,int>mp;
int dis[4*N][4*N],vis[4*N];
priority_queue<node>q;

void dijkstra(int d){
    cout << d << endl;
    while(!q.empty())q.pop();
    for(int i = 1;i <= cnt;i++)dis[d][i] = inf,vis[i] = 0;
    for(int i = 0;i < g[d].size();i++)dis[d][g[d][i].id] = g[d][i].val,q.push({g[d][i].id,g[d][i].val});
    dis[d][d] = 0;vis[d] = 1;
    int nk = cnt-1;
    while(nk--){
        node bbb = q.top();
        q.pop();
        vis[bbb.id] = 1;
        for(int i = 0;i < g[bbb.val].size();i++){
            int ji = g[bbb.id][i].id,jv = g[bbb.id][i].val;
            if(!vis[ji] && dis[d][ji] > jv+bbb.val){
                dis[d][ji] = jv+bbb.val;
                q.push({ji,dis[d][ji]});
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read(),n = read(),m = read(),d = read(),p = read();
    cnt = m;
    for(int i = 1;i <= m;i++){
        int u = read();
        g[i].push_back({++cnt,u});
        g[cnt].push_back({i,u});
        mp[u] = cnt;
    }
    for(int j = 1;j <= n;j++){
        int k = read();
        int t = ++cnt;
        for(int i = 1;i <= k;i++){
            int e = read(),f = read();
            g[++cnt].push_back({mp[e],f});
            g[mp[e]].push_back({cnt,f});
            g[t].push_back({cnt,0});
            g[cnt].push_back({t,0});
        }
    }
    cout << cnt << endl;
    for(int i = 1;i <= cnt;i++)dijkstra(i);
    while(p--){
        int u = read(),v = read();
        cout << dis[u][v] << endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
