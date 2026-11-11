#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int a[500001],d[500010];
bool b[500001];
vector<int> f[500001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (n <= 5000)
    {
        for (int k = 0;k<n;k++)
        {
            stack<pii> q;
            for(int i = 1;i<=n;i++)
            {
                b[i] = false;
            }
            for (int i = k+1;i<=n;i++)
            {
                if (b[a[i]])
                {
                    while (!q.empty() && q.top().first != a[i])
                    {
                        b[q.top().first] = false;
                        q.pop();
                    }
                    q.pop();
                    q.push({a[i],i});
                }
                else
                {
                    b[a[i]] =  true;
                    q.push({a[i],i});
                }
            }
            for (int i = 1;i<=m;i++)
            {
                if (b[i])
                {
                    d[i]++;
                }
            }
        }
        for (int i = 1;i<=m;i++)
        {
            cout << d[i] << " ";
        }
    }
    else if (m > 2)
    {
        int t = unique(a+1,a+n+1)-a-1,s = 0;
        for (int i = 1;i<=t;i++)
        {
            d[a[i]] += t-i+1;
        }
        for (int i = 1;i<=m;i++)
        {
            cout << d[i] << " ";
        }
    }
    else
    {
        if (m == 2)
        {
            int s1 = 0,s2 = 0;
            for (int i = 1;i<=n;i++)
            {
                if (a[i] == 1 && a[n] == 2 || a[i]==2 && a[n] == 1)
                {
                    s1++;
                    s2++;
                }
                else if (a[i] == 1 && a[n] == 1)
                {
                    s1++;
                }
                else
                {
                    s2++;
                }
            }
            cout << s1 << " " << s2;
        }
        else
        {
            cout << n;
        }
    }
    return 0;
}
