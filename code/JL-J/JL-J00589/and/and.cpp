#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int son[N][2];
int a[N],idx;
int cnt[N],counts[N];
int n,m;
int num[N];
bool st[N];
int anss = 0;
void dfs(int start,int u)
{
    if (u > m)
    {
 //       cout << "*******" << endl;
 //       for (int i = 1;i <= m;i ++)
 //       {
  //          cout << num[i] << ' ';
  //      }
  //      cout << endl;
        int res = a[num[1]];
        for (int i = 2;i <= m;i++)
        {
            res = res & a[num[i]];
        }
 //       cout << "res:" << res << endl;
        anss = max(anss,res);
    }
    for (int i = start;i <= n;i ++)
    {
        if (!st[i])
        {
            st[i] = true;
            num[u] = i;
            dfs(i + 1,u + 1);
            st[i] = false;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if (m == 1)
    {
        int maxs= 0;
        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i];
            maxs = max(maxs,a[i]);
        }
        cout << maxs << endl;
        return 0;
    }
    if (m == 2)
    {
        int ans = 0;
        for (int i = 1;i <= n;i ++)cin >> a[i];
        for(int i = 1;i <= n;i ++)
        {
            int res = 0;
            for (int j = 1;j <= n;j ++)
            {
                if (i!=j)
                    res = max(res,a[i] & a[j]);
            }
            ans = max(ans,res);
        }
        cout << ans << endl;
    }
    else
    {
        for (int i = 1;i <= n;i ++)cin >> a[i];
        dfs(0,0);
        cout << anss << endl;
    }
    return 0;
}
/**
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int son[N][2];
int a[N],idx;
int cnt[N],counts[N];
int main()
{
    freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if (m == 1)
    {
        int maxs= 0;
        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i];
            maxs = max(maxs,a[i]);
        }
        cout << maxs << endl;
        return 0;
    }
    if (m == 2)
    {
        int ans = 0;
        for(int i = 1;i <= n;i ++)
        {
            int res = 0;
            for (int j = 1;j <= n;j ++)
            {
                res = max(res,i & j);
            }
            ans = max(ans,res);
        }
        cout << ans << endl;
        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i];
            int p = 0;
            for (int j = 31;j >= 0;j --)
            {
                int u = a[i] >> j & 1;
                if (!son[p][u])
                {
                    son[p][u] = ++idx;
                }
                p = son[p][u];
            }
            cnt[p] ++;
        }
        int ans = 0;
        for (int p1 = 1;p1 <= n;p1 ++)
        {
            int t = a[p1];
            int res = 0;
            int p = 0;
            for (int j = 31;j >= 0;j --)
            {
                int u = t >> j & 1;
                if (son[p][u] && u)
                {
                    res = res * 2 + 1;
                    //if (t == 15) cout << u << ' ' << 1 << endl;
                }
                else if(son[p][u] && !u)
                {
                    res = res * 2;
                    //if (t == 15) cout << u << ' ' << 0 << endl;
                }
                else if (son[p][!u])
                {
                    res = res * 2;
                    //if (t == 15 ) cout << u << ' ' << 0 << endl;
                }
                p = son[p][u];
            }
            //cout << ':' << res << endl;
            if (cnt[p] == 1 && res == t & t);
            else ans = max(ans,res);
        }
        cout << ans<< endl;
    }
    return 0;
}
**/
