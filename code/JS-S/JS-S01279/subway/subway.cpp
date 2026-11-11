#include <bits/stdc++.h>
#define  pi pair<ll,ll>
using namespace std;

typedef long long ll;
const int N = 5e5+5;
const int N2 = 5e5+505;
const int Q = 1e5+5;


int c,n,m,d,q;
ll w[N];
int k[505];
ll a,t;
//int x[Q],y[Q];

struct edge{
    ll v,w;
};

vector<edge>e[N2];
int cnt = 0;

ll ans[Q];
ll di[N2];

void dij(int s){

    bool vis[N2];

    for(int i=1;i<=n+m;i++)vis[i] = 0,di[i] = 1e18;
    di[s] = 0;
    priority_queue<pi,vector<pi>,greater<pi>>p;
    p.push({0,s});
    while(!p.empty()){
        int u = p.top().second;
        p.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto tmp:e[u]){
            ll tt = tmp.w;
            int v = tmp.v;
            if(di[v] > di[u] + tt){
                di[v] = di[u] + tt;
                p.push({di[v],v});
            }
        }
    }
}

struct question{
    int x,y,id;
}cyr[Q];

bool cmp(question xx,question yy){
    return xx.x < yy.x;
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    int tmp = n;
    for(int i=1;i<=tmp;i++){
        cin >> k[i];

        for(int j=1;j<=k[i];j++){
            cin >> a >> t;
            if(k[i] == 1){
                n--;
                continue;
            }
             e[a].push_back({i+m,t});
             e[i+m].push_back({a,t});

        }
    }



    for(int i=1;i<=q;i++){
        cin >> cyr[i].x >> cyr[i].y;
        cyr[i].id = i;
    }

    sort(cyr+1,cyr+1+q,cmp);

    for(int i=1;i<=q;i++){
        if(cyr[i].x != cyr[i-1].x)dij(cyr[i].x);
        ans[cyr[i].id] = w[cyr[i].x] + w[cyr[i].y] + di[cyr[i].y];
    }

    for(int i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}
