#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
ll m,sum[maxn],a[maxn];
int n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) 
    {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 1,l = 1;
    for(int r = 2;r <= n;r++)
    {
        while(1ll * (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m) l++;
        ans = max(ans,r - l + 1);
        // cout << l << ' ' << r << '\n';
    }
    cout << ans << '\n';
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/