#include <bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define ll long long
int const MAXN = 2e6 + 5;
ll n, step, a[MAXN], ans;
vector<int> e[MAXN], eb[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out", "w" ,stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        ans = 0;
        cin >> n >> step;
        for(int i = 1; i <= n; i++) {
            e[i].clear();
            eb[i].clear();
        }
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(a[j] - a[i] <= step) {
                    e[i].push_back(j);
                    eb[j].push_back(i);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i + 2; j <= n; j++) {
                int sum = 0;
                for(int d : e[i]) {
                    for(int d1 : eb[j]) {
                        if(d == d1) {
                            sum++;
                        }
                    }
                }
                if(sum == 2) ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}