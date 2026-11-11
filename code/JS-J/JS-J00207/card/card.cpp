#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], c[M], ans[M];
void op(int l, int r) {
    if(l > r) return ;
    c[a[l]]++;
    for(int i = r; i >= 1; i--) {
        if(a[i] == a[l]) {
            op(i + 1, r); break;
        }
    }
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, j;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) c[j] = 0;
        op(i, n);
        for(int j = 1; j <= m; j++) ans[j] += c[j];
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
