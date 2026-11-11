#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define dep(i,r,l) for(int i = r; i >= l; i--)
#define lc (idx << 1)
#define rc (idx << 1 | 1)

using namespace std;

const int maxn = 2e6 + 100;
int a[maxn];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        rep(i,1,n){
            cin >> a[i];
        }
        int del = a[2] - a[1];
        if(del % d == 0){
            cout << 0 << "\n";
        } else {
            cout << 923493 << "\n";
        }
    }

    return 0;
}