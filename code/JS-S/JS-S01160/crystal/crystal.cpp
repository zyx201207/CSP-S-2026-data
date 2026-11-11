#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    
    sort(a.begin() + 1, a.end());
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        p[i] = p[i - 1] + a[i];
    }

    int l = 1, r = 1;
    int ans = 1;
    while (r <= n){
        int c = a[r] * (r - l + 1) - p[r] + p[l - 1];
        if (c <= m){
            ans = max(ans, (r - l + 1));
            r++;
        }
        else{
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}