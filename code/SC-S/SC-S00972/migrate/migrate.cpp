#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 15;
const int N1 = 5005;
int c,n;
ll d,a[N];
namespace subtask1{
    bool check(){
        return (c <= 10);
    }
    void work(){
        int cnt = 0;
        for(int i = 1;i <= n;i ++){
            static int f[N1];
            static ll g[N1];
            for(int j = i;j <= n;j ++) f[j] = g[j] = 0;
            int m = n;
            for(int j = i + 1,fr = i;j <= n;j ++){
                while(fr <= n && a[j] - a[fr] > d) fr ++;
                if(fr == j) {m = j - 1;break;}
                f[j] = f[fr] + 1;
            }
            g[i] = 1;
            for(int j = i + 1,fr = i,nt = i;j <= m;j ++){
                while(fr <= m && a[j] - a[fr] > d) fr ++;
                while(nt < m && f[nt + 1] <= f[fr]) nt ++;
                if(nt == fr) g[j] = g[fr];
                else if(nt - fr == 1){
                    g[j] = g[fr] * (nt - fr + 1);
                }
                if(g[j] == 2) cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}
namespace subtask2{
    bool check(){
        return (c <= 12);
    }
    void work(){
        ll dt = a[2] - a[1];
        ll p = d / dt;
        if(p <= 1) return cout << "0\n",void(0);
        ll sum = max(n - p * 2 + 1,0ll);
        cout << sum << '\n';
    }
}
namespace subtask3{
    bool check(){
        return (c <= 14);
    }
    void work(){
        ll cnt = 0;
        for(int i = 2;i < n;i ++){
            ll pl = a[i] - d,pr = a[i + 1] - d;
            ll sl = a[i - 1] + d + 1,sr = a[i] + d;
            int tl = lower_bound(a + 1,a + 1 + n,pr) - upper_bound(a + 1,a + 1 + n,pl);
            int tr = lower_bound(a + 1,a + 1 + n,sr) - upper_bound(a + 1,a + 1 + n,sl);
            cnt += 1ll * (tl + 1) * (tr + 1);
        }
        cout << cnt << '\n';
    }
}
void solve(){
    cin >> n >> d;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    if(subtask1::check()) return subtask1::work();
    if(subtask2::check()) return subtask2::work();
    if(subtask3::check()) return subtask3::work();
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;cin >> c >> T;
    while(T --) solve();
    return 0;
}