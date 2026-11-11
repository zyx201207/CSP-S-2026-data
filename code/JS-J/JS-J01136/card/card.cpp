#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010], b[500010];
bool f[300010];
int id[500010];
int uid[300010];

signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cout << n << ' ';
    cout << "\n";
    return 0;
}
