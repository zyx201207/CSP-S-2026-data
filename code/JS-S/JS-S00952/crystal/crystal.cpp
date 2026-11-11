#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans[N], maxa;
long long m, a[N], pre[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    int r = 1;
    for(int i = 2;i <= n;i++)
    {
        while((i - r) * a[i] - (pre[i - 1] - pre[r - 1]) > m)
        {
            r++;
        }
        ans[i] = i - r + 1;
    }
    for(int i = 1;i <= n;i++)
    {
        maxa = max(ans[i], maxa);
    }
    cout << maxa;
    return 0;
}

//14:30 - 15:02