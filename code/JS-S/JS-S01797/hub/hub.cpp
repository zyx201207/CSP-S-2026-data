#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000001];
int n;
bool check(int x)
{
    return 1;
}
int bf(int t)
{
    int l = 0, r = n - 1;
    while(r - 1 > l)
    {
        int mid = (l + r) / 2;
        if(!check(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    if(check(l))
    {
        return l;
    }
    else
    {
        return n - 1;
    }
}
void solve()
{
    int k;
    cin >> n >> k;
    for(int i = 1;i < n;i ++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int t = bf(k);
    cout << t;
}
int main()
{
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}
/*
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
AC!I hope to get more than 120
*/
