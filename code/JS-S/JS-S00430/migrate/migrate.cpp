#include <bits/stdc++.h>
#define ll long long int
#define fi first
#define se second
#define rep(i, f, t) for(int i = f ; i <= t ; ++i)
#define per(i, f, t) for(int i = f ; i >= t ; --i)
#define all(x) x.begin() x.end()
#define re return
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tupii pair<int, pii>
#define t1 fi
#define t2 se.fi
#define t3 se.se

using namespace std;
ll c, t, n, d;
ll x[2000007];
ll res = 0;
int atag[2000007], btag[2000007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        res = 0;
        cin >> n >> d;
        int u = 1, f = 1, t = 1;
        while(t != n && x[t] - x[u] <= d)t++;
        t--;
        rep(i, 1, n)cin >> x[i];
        rep(v, 2, n){
            while(x[v] - x[f] > d)f++;
            while(t - f + 1 < 2){
                u++;
                while(t != n && x[t] - x[u] <= d)t++;
                t--;
            }
            if(t - f + 1 == 2)atag[u]++, btag[v]++, res++;
        }
        cout << res << endl;
        rep(i, 1, n)atag[i] = btag[i] = 0;
    }
    re 0;
}
