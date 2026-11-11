#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int n,m;
int mx = 0;
int ans[N];
void dfs(int now,int cnt)
{
    if(now == n + 1)
    {
        if(cnt == m)
        {
            int ret = ans[1];
            for(int i = 2;i <= m;i++)
            {
                ret = ret & ans[i];
            }
            mx = max(mx,ret);
        }
        return;
    }
    ans[cnt] = a[now];
    dfs(now + 1,cnt + 1);
    dfs(now + 1,cnt);
}
map<int,int>mp;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(n <= 20)
    {
        dfs(1,0);
        cout << mx;
    }
    else if(n <= 2000)
    {
        if(m == 1)
        {
            mx = -1;
            for(int i = 1;i <= n;i++)
            {
                mx = max(mx,a[i]);
            }
            cout << mx;
        }
        else if(m == 2)
        {
            mx = 0;
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    mx = max(mx,a[i] & a[j]);
                }
            }
            cout << mx;
        }
        else if(m == n)
        {
            mx = a[1];
            for(int i = 2;i <= n;i++)
            {
                mx = mx & a[i];
            }
            cout << mx;
        }
    }
    else
    {
        bool flag = false;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] != i - 1)
            {
                flag = true;
            }
        }
        bool f = false;
        for(int i = 2;i <= INT_MAX;i *= 2)
        {
            if(i - 1 == n)
            {
                f = true;
            }
        }
        if(!flag && f)
        {
            int cnt = a[n];
            for(int i = n - 1;i >= n - m + 1;i--)
            {
                cnt = cnt & a[i];
            }
            cout << cnt;
        }
        else
        {
            bool ff = false;
            for(int i = 1;i <= n;i++)
            {
                if(1 << log2(a[i] + 1) != a[i] + 1)
                {
                    ff = true;
                }
            }
            if(!ff)
            {
                sort(a + 1,a + n + 1,greater<int>());
                int big = a[m] / 2 + 1;
                int ret = 0;
                while(big > 0)
                {
                    ret += big;
                    big /= 2;
                }
                cout << ret;
            }
            else
            {
                for(int i = 1;i <= n;i++)
                {
                    int num = a[i];
                    int tmp;
                    for(int i = 1;i <= num;i *= 2)
                    {
                        tmp = i;
                    }
                    while(num > 0)
                    {
                        if(num >= tmp)
                        {
                            mp[tmp]++;
                            num -= tmp;
                        }
                        tmp /= 2;
                    }
                }
                map<int,int>::iterator it;
                int ret = 0;
                for(it = mp.begin();it != mp.end();it++)
                {
                    if(it->second >= m)
                    {
                        ret += it->first;
                    }
                }
                cout << ret;
            }
        }
    }
    return 0;
}
