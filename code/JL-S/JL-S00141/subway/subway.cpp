#define dps 799
#define I dryer
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<ctime>
#include<vector>
using namespace std;
#define int long long
typedef vector<int> vv;
#define x first
#define y second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef vector<vv> vvv;
const int N = 520, M = 500200, inf=1e18;
int w[M];
// vv vt[N];
vp g[M<<2];
// int pat[N][N];
inline void svc(int c,int n,int m,int d,int q){
    int cc = 0;
    clock_t sts = clock();
    vvv pat(m+1, vv(n+m+2,inf));
    for(int i=1;i<=m;++i) cin >> w[i];
    for(int i=1;i<=n;++i){
        int k;cin>>k;
        while(k--){
            int x,y;cin >> x >> y;
            g[i+m].pb({x,y}); g[x].pb({i+m,y});
        }
    } 
    for(int S=m+1;S<=m+n;++S){
        queue<int> q; q.push(S);
        pat[S-m][S] = 0;
        while(q.size()){
            int px=q.front(); q.pop();
            for(auto [x,y]:g[px]){
                // ++ cc;
                if(pat[S-m][x] > pat[S-m][px]+y){
                    pat[S-m][x] = pat[S-m][px]+y;
                    q.push(x);
                }
            }
        }
    }
    // cout << cc << ' ' << (double) (clock()-sts)/CLOCKS_PER_SEC << endl; return;
    // for(int i=1;i<=n;++i) {
    //     for(int j=1;j<=n+m;++j){
    //         cout << pat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    while(q--){
        int x,y;cin>>x >> y;
        int mn = inf;
        for(int i=1;i<=n;++i){
            int sb = pat[i][x]+pat[i][y];
            if(sb < mn) mn = sb;
        }
        cout << mn + w[x]+w[y] << '\n';
    }
}
signed main(){
    // clock_t sts = clock();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c,d,q,n,m;cin>>c >> n >> m >> d >> q;
    if(12 <= c && c <= 19) return svc(c,n,m,d,q), 0;
    vvv pat(m+2, vv(n+m+3,inf));
    for(int i=1;i<=m;++i) cin >> w[i];
    for(int i=1;i<=n;++i){
        int k;cin>>k;
        while(k--){
            int x,y;cin >> x >> y;
            g[i+m].pb({x,y}); g[x].pb({i+m,y});
        }
    } 
    vv st(n+m+2, 0); 
    for(int S=m+1;S<=m+n;++S){
        priority_queue<pii, vp, greater<pii> > q; q.push({0,S});
        pat[S-m][S] = 0;
        while(q.size()){
            pii p = q.top(); q.pop();
            if(st[p.y]==S) continue; st[p.y] = S;
            for(auto [x,y]:g[p.y]){
                if(pat[S-m][x] > pat[S-m][p.y]+y){
                    pat[S-m][x] = pat[S-m][p.y]+y;
                    q.push({pat[S-m][x],x});
                }
            }
        }
    }
    // cout << (double) (clock()-sts)/CLOCKS_PER_SEC << endl; return 0;
    // for(int i=1;i<=n;++i) {
    //     for(int j=1;j<=n+m;++j){
    //         cout << pat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    while(q--){
        int x,y;cin>>x >> y;
        int mn = inf;
        for(int i=1;i<=n;++i){
            int sb = pat[i][x]+pat[i][y];
            if(sb < mn) mn = sb;
        }
        cout << mn + w[x]+w[y] << '\n';
    }
}