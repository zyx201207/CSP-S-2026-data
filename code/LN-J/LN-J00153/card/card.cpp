#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[300005],c[500005];
queue <long long> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {

        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 1;i<=n;i++)
        {
            for (int j = 1;j<i;j++)
            {
                if (a[j] == a[i])
                {
                    while (!q.empty()) q.pop();
                    for (int k = 1;k<i;k++) a[k] = 0;
                    break;
                }
            }
            q.push(a[i]);
        }
    while (!q.empty())
    {
        b[q.front()]++;
        q.pop();
    }
    for (int i = 1;i<=n;i++)
    {
        a[i] = 0;
    }
    while (n--)
    {
        for (int i = 1;i<=n;i++)
        {
            c[i] = c[i+1];
            a[i] = 0;
        }
        for (int i = 1;i<=n;i++)
        {
            a[i] = c[i];
        }
        for (int i = 1;i<=n;i++)
        {
            for (int j = 1;j<i;j++)
            {
                if (a[j] == a[i])
                {
                    while (!q.empty()) q.pop();
                    break;
                }
            }
            q.push(a[i]);
        }
        while (!q.empty())
        {
            b[q.front()]++;
            q.pop();
        }
    }
    for (int i = 1;i<=m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
