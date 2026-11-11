#include <bits/stdc++.h>
using namespace std;
set<int> tt;
multiset<int> cc;
vector<int> gt;
int a[200005], pw[25];
int qwq = 1, fl = 1, zd, ct = 20, cti, n, m, tot;
bool cmp(int x, int y)
{
    return x > y;
} 
int lowbit(int x)
{
    return x & -x;
} 
int ct1(int x)
{
    int res = 0;
    while (x) x -= lowbit(x), res++;
    return res;
} 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    for (int i = 0; i <= 20; i++)
    {
        tt.insert(qwq - 1);
        pw[i] = qwq - 1;
        qwq *= 2;
    } 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cc.insert(a[i]);
        zd = max(zd, a[i]);
        if (ct1(a[i]) < ct) ct = ct1(a[i]), cti = i;
        if (!tt.count(a[i])) fl = 0;
    } 
    if (fl)
    {
        int x = m, i;
        for (i = 20; i >= 0; i--)
        {
            x -= cc.count(pw[i]);
            if (x <= 0) break;
        }
        cout << pw[i];
        return 0;
    } 
    if (m == 1)
    {
        cout << zd;
        return 0;
    } 
    if (m == n - 1)
    {
        int ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            if (i != cti) ans &= a[i];
        } 
        cout << ans;
        return 0;
    } 
    if (m == n)
    {
        int ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans &= a[i];
        } 
        cout << ans;
        return 0;
    } 
    if (m == 2)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans, a[i] & a[j]);
            } 
        } 
        cout << ans;
        return 0;
    } 
    if (m == 3)
    {
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    ans = max(ans, a[i] & a[j] & a[k]);
                } 
            } 
        } 
        cout << ans;
        return 0;
    } 
    if (m == 4)
    {
        int ans = 0;
        for (int i = 1; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l <= n; l++)
                    {
                        ans = max(ans, a[i] & a[j] & a[k] & a[l]);
                    } 
                } 
            } 
        } 
        cout << ans;
        return 0;
    } 
    if (m == 5)
    {
        int ans = 0;
        for (int i = 1; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        for (int o = l + 1; o <= n; o++)
                        {
                            ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o]);
                        }
                    } 
                } 
            } 
        } 
        cout << ans;
        return 0;
    } 
    return 0;
} 