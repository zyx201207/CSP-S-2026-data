#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int v[500010];
int n, m;
long long ans = 0;
void dfs(int x, long long s)
{
    if(x > m)
    {
        ans = max(ans, s);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!v[i])
        {
            v[i] = 1;
            if(x == 1) dfs(x + 1, a[i]);
            else dfs(x + 1, s & a[i]);
            v[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0);
    cout << ans;
    cout << "\n";
    return 0;
}
