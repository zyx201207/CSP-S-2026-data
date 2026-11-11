#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long ans;
int a[N], b[N], c[N], e[N], p[N], q[N];
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int x, y;
    cin >> x >> y;
    while (y--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(e, 0, sizeof(e));
        memset(p, 0, sizeof(q));
        memset(q, 0, sizeof(p));
        int n, d;
        cin >> n >> d;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i] + d;
        }
        int k=0, x=0;
        for(int i = 0; i < n; i++) {
            while(b[k] >= a[i] && b[k] <= a[i+1]) {
                if(!c[i]) c[i] = k, e[i+1] = k, p[k] = i;
                k++;

            }
        }
        for(int i = 1; i < n; i++) {
            if(c[i]) {
                if(i == c[i]+1) p[i] = c[i];
            }
            if(c[i-1]) {
                ans += (e[i-1]-c[i-1])*(p[i]-e[p[i]]);
            }
        }
        cout << -1*ans << '\n';
    }
}
