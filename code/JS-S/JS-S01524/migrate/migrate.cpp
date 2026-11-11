#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

ll n,d;
ll ar[2000006];
ll vis[2000006];
ll dis[2000006];

struct Node{
    ll u,step;
};

void bfs(ll start){
    repe(i,1,n) vis[i] = dis[i] = 0;
    queue<Node> q;
    q.push({start,0});
    vis[start] = 1;
    while(q.size()){
        auto f = q.front();q.pop();
        ll u = f.u,st = f.step;
        //cout << u << ' ' << d << '\n';
        //cout << (ar[u+1]-ar[u] <= d) << '\n';
        //cout << (ar[u+1]-ar[u]) << '\n';
        //cout << "d" << d << '\n';
        for(ll i = u+1;i <= n && ar[i]-ar[u] <= d;i++){
            //cout << "bfs_i:" << i << '\n';
            if(vis[i]){
                if(dis[i] == st+1){
                    vis[i] += vis[u];
                }
            }else{
                vis[i] = vis[u];
                dis[i] = st+1;
                q.push({i,st+1});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin >> c >> t;
    while(t--){
        //cout << t << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        cin >> n >> d;
        repe(i,1,n){
            cin >> ar[i];
        }
        ll ans = 0;
        repe(i,1,n){
            //cout << "i:" << i << '\n';
            bfs(i);
            repe(j,1,n){
                //cout << j << ':' << dis[j] << ' ' << vis[j] << '\n';
                ans += (vis[j] == 2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}