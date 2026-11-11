#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll p = (1ll << 31) - 1;

int n, m;
ll ans, a[200005], p2[32];

void dfs(int x, int k, ll s){
    if(k == m){
        ans = max(s, ans);
        return;
    }
    if(s <= ans || x >= n)
        return;
    for(int i = x + 1;i <= n;i++)
        dfs(i, k + 1, s & a[i]);
    dfs(x + 1, k, s);
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    p2[0] = 1;
    for(int i = 1;i <= 31;i++)
        p2[i] = p2[i - 1] * 2;
    cin >> n >> m;
    bool flag = 1, ff;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        ff = 0;
        for(int j = 1;j <= 31;j++){
            if(a[i] == p2[j] - 1){
                ff = 1;
                break;
            }
        }
        flag &= ff;
    }
    if(m == 1)
        cout << *max_element(a + 1, a + n + 1);
    else if(m == n){
        ans = p;
        for(int i = 1;i <= n;i++)
            ans &= a[i];
    }
    else if(flag){
        sort(a + 1, a + n + 1);
        ans = p;
        for(int i = n;i > n - m;i--)
            ans &= a[i];
    }
    else{
        dfs(0, 0, p);
    }
    cout << ans;
    return 0;
}
