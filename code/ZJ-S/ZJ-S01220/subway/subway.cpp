#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
const int num = 500005;
const int inf = 1e15;
vector<pii>pa[num];
int dis[505][505];
int n,m,C,D,T,co[num];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>n>>m>>D>>T;
    F(i,1,m)cin>>co[i];
    F(i,1,n){
        int k;
        cin >> k;
        F(j,1,k){
            int a,t;
            cin>>a>>t;
            pa[a].pb(pii(i, t));
        }
    }
    F(i, 1, n)
        F(j, 1, n) dis[i][j] = inf;
    F(i,1,n)dis[i][i]=0;
    F(i,1,m){
        for(pii x:pa[i]){
            for(pii y:pa[i]){
                int u = x.fi, v = y.fi;
                if(u!=v){
                    dis[u][v] = dis[v][u] = min(dis[u][v], x.se + y.se);
                // cerr << u << ' ' << v << ' ' << x.se + y.se << endl;
                }
                
            }
        }
    }
    F(i,1,n){
        F(j,1,n){
            F(k,1,n){
                if(i!=j&&j!=k){
                    dis[k][j] = dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }
    }
    // F(i, 1, n)
    //     F(j, 1, n) cout << i << ' ' << j << endl;
    while(T--){
        int x,y;
        cin>>x>>y;
        int mx = inf;
        for(pii a:pa[x]){
            for(pii b:pa[y]){
                int u = a.fi,v=b.fi;
                mx = min(mx, dis[u][v]+a.se+b.se);
            }
        }
        cout << mx + co[x] + co[y] << endl;
    }
}