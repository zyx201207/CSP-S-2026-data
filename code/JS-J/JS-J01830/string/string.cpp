#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e5 + 5;

int a[N];
int v[N];
char c[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    LL len = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        len += a[i];
    }
    LL ans = 0;
    int l = 1, r = n;
    while (l < r){
        LL d = min(a[l] - v[l], a[r] - v[r]);
        v[l] += d;
        v[r] += d;
        if (c[l] != c[r]){
            ans += d;
        }
        if (v[l] == a[l]){
            l++;
        }
        if (v[r] == a[r]){
            r--;
        }
    }
    cout << ans;

    return 0;
}
