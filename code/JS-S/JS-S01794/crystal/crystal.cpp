#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int mx = -1;
int a[N], s[N];
bool judge(int x, int y) {
    int tmp = s[y - 1] - s[x - 1];
    return (a[y] * (y - x) - tmp <= m);
}
int solve(int x) {
    int l = 1, r = x - 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(judge(mid, x))
            r = mid;
        else
            l = mid + 1;
    }
    return (x - r + 1);
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for(int i = n; i >= 1; i--) 
        mx = max(solve(i), mx);
    cout << mx;
    return 0;
}
/*
14:50 AC 100pts
*/