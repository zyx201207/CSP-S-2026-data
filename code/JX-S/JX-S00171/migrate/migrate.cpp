#include <bits/stdc++.h>
#define il inline
#define rg register
#define int ll
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
namespace XXI{
    const int maxn = 2e6+50;
    const char endl = '\n';
    int cf[maxn];
    int dis[maxn];
    int n,d;
    int pos[maxn];
    int ans;
    int c,t;
    il void init(){
        for(int i = 1;i<=n+1;i++){
            pos[i] = dis[i] = cf[i] = 0;
        }
        n = d = ans = 0;
    }
    il void bfs(int s){
        for(int i = 1;i<=n+1;i++){
            cf[i] = 0;
            dis[i] = 0x7f7f7f7f;
        }
        int l = s,r = s,posl = s+1;
        dis[s] = 0;
        dis[s+1] = 1;
        int now = 0;
        cf[s] = 1;
        cf[s+1] = -1;
        while(l<=r){
            now += cf[l];
            if(now == 2) ans++;
            while(pos[r+1]-pos[l]<=d){
                r++;
                dis[r] = dis[l]+1;
                if(dis[posl]!=dis[r]) posl = r;
            }
            if(dis[posl]!=dis[l]){
                cf[posl] += now;
            }
            if(dis[posl]!=dis[l])cf[r+1] -= now;
            l++;
        }
    }
    il void work(){
        init();
        cin >> n >> d;
        ans = 0;
        for(int i = 1;i<=n;i++){
            cin >> pos[i];
        }
        if(c>10){
            cout << n*(n-1)/2 << endl;
            return ;
        }
        pos[n+1] = 4e18;
        for(int i = 1;i<=n;i++){
            bfs(i);
        }
        //bfs(1);
        cout << ans << endl;
    }
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        cin >> c >> t;
        while(t--){
            work();
        }
        return 0;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    XXI::main();
    return 0;
}
