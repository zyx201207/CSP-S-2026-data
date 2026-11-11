#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll m;
const int MAXN = 5e5 + 10;
ll a[MAXN], sum[MAXN];
bool check(int x)
{
    for(int i = x; i <= n; ++i)
    {
        ll s = a[i] * x - (sum[i] - sum[i - x]);
        if (s <= m) return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i]; 
    //for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    //cout << '\n';
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}