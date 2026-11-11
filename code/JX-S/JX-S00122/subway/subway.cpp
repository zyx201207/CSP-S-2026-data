/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include <bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
intc N=505,M=5e5+10;
constexpr intl inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
intl w[M],k[N];
struct subways {
    int a;
    intl t;
};
vector <subways> sub[M],lne[N];
struct station {
    int id;
    intl t;
    int frm;
    bool operator < (const station &p) const {return t>p.t;}
};
intl dis[M];
bool vis[M],visa[N];
struct query {
    int y,id;
};
vector <query> que[M];
intl res[M];
signed main () {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // auto _start_clock=clock();
    Cios;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        cin>>k[i];
        for (int j=1;j<=k[i];j++) {
            int _a;
            intl _t;
            cin>>_a>>_t;
            sub[_a].push_back({i,_t});
            lne[i].push_back({_a,_t});
        }
    }
    if (m>q) {
        while (q--) {
            int x,y;
            cin>>x>>y;
            priority_queue<station> pq;
            memset(dis,0x3f,sizeof dis);
            memset(vis,0,sizeof vis);
            memset(visa,0,sizeof visa);
            dis[x]=0;
            pq.push({x,0,0});
            while (pq.size()) {
                auto [id,nwt,frm]=pq.top();pq.pop();
                if (vis[id]) continue;
                if (id==y) break;
                vis[id]=1;
                visa[frm]=1;
                for (auto [ai,at]:sub[id]) {
                    if (visa[ai]) continue;
                    for (auto [ii,iit]:lne[ai]) {
                        if (dis[ii]>nwt+at+iit) {
                            dis[ii]=nwt+at+iit;
                            pq.push({ii,dis[ii],ai});
                        }
                    }
                }
            }
            cout<<dis[y]+w[x]+w[y]<<"\n";
        }
    }
    else {
        for (int i=1;i<=q;i++) {
            int x,y;
            cin>>x>>y;
            que[x].push_back({y,i});
        }
        for (int x=1;x<=m;x++) {
            if (que[x].empty()) continue;
            priority_queue<station> pq;
            memset(dis,0x3f,sizeof dis);
            memset(vis,0,sizeof vis);
            memset(visa,0,sizeof visa);
            dis[x]=0;
            pq.push({x,0,0});
            while (pq.size()) {
                auto [id,nwt,frm]=pq.top();pq.pop();
                if (vis[id]) continue;
                vis[id]=1;
                visa[frm]=1;
                for (auto [ai,at]:sub[id]) {
                    if (visa[ai]) continue;
                    for (auto [ii,iit]:lne[ai]) {
                        if (dis[ii]>nwt+at+iit) {
                            dis[ii]=nwt+at+iit;
                            pq.push({ii,dis[ii],ai});
                        }
                    }
                }
            }
            for (auto [y,id]:que[x]) res[id]=dis[y]+w[x]+w[y];
        }
        for (int i=1;i<=q;i++) cout<<res[i]<<"\n";
    }
    // auto _stop_clock=clock();
    // cerr<<(_stop_clock-_start_clock)/1e6<<"\n";
    return 0;
}

/*
g++ -g subway.cpp -o subway -O2 -std=c++14 -static && echo "finish" && ./subway && rm subway
*/