#include<bits/stdc++.h>
using namespace std;

long long n, m, ans, a[200005];

bool cmp(long long a, long long b)
{
    int pa = __builtin_popcountll(a);
    int pb = __builtin_popcountll(b);
    if(a == b)
    {
        return pa > pb;
    }
    else
    {
        return a > b;
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    ans = a[1];
    for(int i = 2; i <= m; i++)
    {
        ans &= a[i];
    }
    cout << ans << endl;
    return 0;
}