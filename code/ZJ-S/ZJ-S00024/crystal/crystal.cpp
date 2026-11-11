#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll m, ans, a[500005];

ll dfs(int l, int r, int p, ll mn, ll m){
    m -= (p - l + 1) * mn;
    if(l <= 1 || a[r] - a[l - 1] >= a[r + 1] - a[r]){
        mn = a[r + 1] - a[r];
        p = r++;
        for(;a[r + 1] == a[p + 1];r++);
        if((p - l + 1) * mn >= m)
            return m / mn + r - p;
        else
            return dfs(l, r, p, mn, m);
    }
    else if(r >= n || a[r + 1] - a[r] > a[r] - a[l - 1]){
        mn = a[r] - a[l - 1];
        p = l--;
        for(;a[l - 1] == a[p - 1];l--);
        if((p - l + 1) * mn >= m)
            return m / mn + r - p;
        else
            return dfs(l, r, p, mn, m);
    }
    return 0;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int p, l, r;
    ll mn = LLONG_MAX;
    for(int i = 1;i < n;i++){
        if(a[i + 1] != a[i])
            mn = min(mn, a[i + 1] - a[i]);
    }
    if(mn > m)
        cout << 1;
    else{
        for(p = 1;p < n;p++){
            if(a[p + 1] - a[p] == mn){
                if(p == 1 || a[p] != a[p - 1])
                    l = p;
                else
                    for(l = p - 1;l > 0 && a[l - 1] == a[p];l--);
                if(p + 1 == n || a[p + 1] != a[p + 2])
                    r = p + 1;
                else
                    for(r = p + 2;r <= n && a[r + 1] == a[p + 1];r++);
                if((p - l + 1) * mn > m)
                    ans = max(ans, m / mn + r - p);
                else
                    ans = max(ans, dfs(l, r, p, mn, m));
            }
        }
        cout << ans;
    }
    return 0;
}
