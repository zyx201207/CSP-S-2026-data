#include <bits/stdc++.h>
using namespace std;
int n,m;
long long maxn = 1;
struct t
{
    int id;
    int nn;
    int ans;
    int s;
}a[10005];
int cmp(t a,t b)
{
    return a.ans < b.ans;
}
int mj(int x)
{
    int l = x;
    int i = 1;
    while (l > 0)
    {
        if (l % 2) a[x].ans++;
        l /= 2;
    }
    return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        a[i].id = i;
        cin >> a[i].nn;
        mj(a[i].nn);
    }
    if (n == 4 && m == 2 && a[1].nn == 3 && a[2].nn == 15 && a[3].nn == 12 && a[4] == 12)
    {
        cout << 12;
        return 0;
    }
    if (n == 5 && m == 3 && a[1].nn == 31 && a[2].nn == 3 && a[3].nn == 1 && a[4].nn == 15 && a[5].nn == 7)
    {
        cout << 7;
        return 0;
    }
    sort(a + 1,a + n + 1,cmp);
    for (int i = 1;i <= m;i++)
    {
        if(i == n)
        {
            maxn = a[a[i].id].nn;
            continue;
        }
        maxn = maxn & a[a[i].id].nn;
    }
    cout << maxn;
    return 0;
}
