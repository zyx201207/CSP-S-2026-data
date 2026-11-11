#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,m;
const int maxn = 1e3 + 10;
int R = 1e18;
int a[maxn],dis[maxn],num[maxn],vis[maxn];
vector<int>v[maxn];
namespace sub1{
    bool check(int x,int y) {
        for(int i = 1 ; i <= n ; i ++) {
            num[i] = 0;
            dis[i] = R;
            vis[i] = 0;
        }
        queue<int>q;
        q.push(x);
        dis[x] = 0;
        vis[x] = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for(auto itr:v[u]) {
                //cout << "u:" << u << " itr:" << itr << " dis[" << u << "]:" << dis[u] << " dis[" << itr << "]:" << dis[itr] << '\n';
                if(dis[itr] == dis[u] + 1) num[itr] ++;
                else if(dis[itr] > dis[u] + 1) {
                    num[itr] = 1;
                    dis[itr] = dis[u] + 1;
                }
                if(!vis[itr]) {
                    q.push(itr);
                    vis[itr] = 1;
                }
                //cout << "u:" << u << " itr:" << itr << " dis[" << u << "]:" << dis[u] << " dis[" << itr << "]" << dis[itr] << '\n';
                //cout << "num[" << itr << "]:" << num[itr] << '\n';
                //cout << '\n';
            }
        }
        return (num[y] == 2);
    }
    void work(){
        int ans = 0;
        for(int i = 1 ; i <= n ; i ++ ) cin >> a[i];
        for(int i = 1 ; i <= n ; i ++) v[i].clear();
        for(int i = 1; i <= n ; i ++) {
            for(int j = i + 1 ; j <= n ; j ++) {
                if(a[j] - a[i] <= m) v[i].push_back(j);
            }

        }
        for(int i = 1 ; i <= n ; i ++) {
            for(int j = i + 1 ; j <= n ; j ++) {
                if(check(i,j)) {
                    ++ ans;
                    //cout << i << ' ' << j;
                    //cout << '\n';
                }
            }
            //for(int i = 1 ; i <= n ; i ++) cout << dis[i] << ' ';
            //cout << '\n';
        }

        cout << ans << '\n';

    }
}
namespace sub2{

    void work() {
        for(int i = 1 ; i <= n ; i ++) cin >> a[i];
        int d = a[2] - a[1];
        if((m / d) != 2) {
            cout << 0 << '\n';
            return;
        }
        cout << n - 3 << '\n';
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while(T --) {
        cin >> n >> m;
        if(c <= 2) sub1::work();
        else if(c == 11 || c == 12) sub2::work();

    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
