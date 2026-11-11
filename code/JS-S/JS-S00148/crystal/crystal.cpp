#include<bits/stdc++.h>
#define int long long
using namespace std;
/* Define & Const */
const int N = 5e5 + 10;
/* Struct */

/* Variables */
int n, m;
int a[N];
int pre[N];
/* Functions */
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}
void init()
{
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x = a[n] - a[i];
        pre[i] = pre[i - 1] + x;
    }
}
int binary_search(int id)
{
    int l = 1;
    int r = id;
    int ans ;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (pre[id - 1] - pre[mid - 1] - (id - mid) * (a[n] - a[id]) > m)
        {
            //cout << "!\n";
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
void solve()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i - binary_search(i) + 1;
        ans = max(ans, tmp);
        //cout << "temp = " << tmp << " ans = " << ans << "\n";
    }
    cout << ans;
}
/* Main */
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    init();
    solve();
}   