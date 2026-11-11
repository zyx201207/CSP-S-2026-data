#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], s[500005], c[500005], ans;
bool check(int x){
    for (int i = x - 1; i < n; i ++){
        if (s[i] - s[i-x+1] - (i - x + 1) * (c[i] - c[i-x+1]) <= m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i ++){
        int t = a[i] - a[i-1];
        c[i-1] = c[i-2] + t;
        s[i-1] = s[i-2] + t * (i - 1);
        //cout << s[i-1] << " ";
    }
    int l = 0, r = n;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
