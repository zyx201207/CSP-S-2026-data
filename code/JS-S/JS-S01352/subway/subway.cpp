#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> line[510];
struct node{
    int line,t;
};
struct state{
    vector<node> line;
    int t[510];
};
struct sub{
    int li,sta,t;
    // bool operator > (const sub &x){
    //     return x.t > t;
    // }
};
state st[500010];
int vis[30][510];
int c,n,m,d,q;
int t[500010];
int ans = 1e18;
void bfs(int s,int e){
    queue<sub> q;
    // ting -> dian
    for(node li : st[s].line){
        q.push({s,li.line,li.t});
        vis[s][li.line] = li.t;
    }
    while(q.size()){
        // sub tp = q.top();
        sub tp = q.front();
        q.pop();
        for(int sta : line[tp.li]){
            //chu
            int dt = tp.t + st[sta].t[tp.li];
            if(sta == e){
                ans = min(ans,dt);
            }
            //jin
            for(node li : st[sta].line){
                if(vis[sta][li.line] <= dt + li.t) continue;
                q.push({sta,li.line,dt + li.t});
                vis[sta][li.line] = dt + li.t;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> t[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int u,v;
            cin >> u >> v;
            line[i].push_back(u);
            st[u].line.push_back({i,v});
            st[u].t[i] = v;
        }
    }
    while(q--){
        ans = 1e18;
        memset(vis,0x3f3f,sizeof vis);
        int x,y;
        cin >> x >> y;
        bfs(x,y);
        ans += t[x] + t[y];
        cout << ans << '\n';
    }
    return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> line[510];
struct node{
    int line,t;
};
struct state{
    vector<node> line;
    int t[510];
};
struct sub{
    int li,sta,t;
    // bool operator > (const sub &x){
    //     return x.t > t;
    // }
};
state st[500010];
int vis[30][510]; // ?
int c,n,m,d,q;
int t[500010];
int ans = 1e18;
vector<sub> dist[510];
void bfs(int s,int e){
    queue<sub> q;
    // priority_queue<sub,vector<sub>,greater<sub>> q;
    // ting -> dian
    for(sub no : dist[s]){
        q.push(no);
        vis[no.sta][no.li] = no.t;
    }
    while(q.size()){
        sub tp = q.front();
        q.pop();
        if(tp.sta == e && !ans){
            ans = tp.t;
            if(!dist[s].empty()) return;
        }
        for(int sta : line[tp.li]){
            //chu
            int dt = tp.t + st[sta].t[tp.li];
            if(sta == e){
                ans = min(ans,dt);
            }
            //jin
            for(sub no : dist[tp.sta]){
                if(vis[no.sta][no.li] >= no.t) continue;
                q.push(no);
                vis[no.sta][no.li] = no.t;
            }
        }
    }
}
void init(){
    // dist
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> t[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int u,v;
            cin >> u >> v;
            line[i].push_back(u);
            st[u].line.push_back({i,v});
            st[u].t[i] = v;
        }
    }
    while(q--){
        ans = 1e18;
        int x,y;
        cin >> x >> y;
        bfs(x,y);
        ans += t[x] + t[y];
        cout << ans << '\n';
    }
    return 0;
}
*/