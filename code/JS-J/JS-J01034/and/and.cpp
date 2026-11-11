#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
int a[MAXN], dp[MAXN];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    dp[1] = a[1] & a[2];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;i++) dp[i] = max(dp[i], dp[i - 1] & a[j]);
    }
    cout<<dp[n];
    return 0;
}
