# include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int n, m, bucket[100];
long long x[MAX], limit, maxvalue;
bool cmp(long long a, long long b){ return (a > b); }
long long topow2(long long k){
    long long t = 1;
    while (t < k) t = t * 2;
    return t;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
        limit = max(limit, x[i]);
    }
    limit = topow2(limit) * 2;
    while (limit > 0){
        for (int i = 1; i <= n; i++){
            if (x[i] >= limit) x[i] -= topow2(x[i]);
        }
        sort(x + 1, x + n + 1, cmp);
        long long ans = x[1];
        for (int i = 2; i <= m; i++){
            ans = ans & x[i];
        }
        maxvalue = max(maxvalue, ans);
        if (ans < maxvalue) break;
        else maxvalue = ans;
        limit = limit / 2;
    }
    cout << maxvalue;
    return 0;
}
