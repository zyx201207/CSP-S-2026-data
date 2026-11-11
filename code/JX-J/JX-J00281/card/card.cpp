#include <bits/stdc++.h>
using namespace std;
int a[500005],c[500005];
bool b[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,x;
    queue <int> q;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            if(!b[a[j]])
            {
                b[a[j]] = 1;
                q.push(a[j]);
            }
            else
            {
                bool d = 1;
                int s = q.size();
                for (int k = 1;k <= s;k++)
                {
                    if (d && q.front() == a[j])
                    {
                        d = 0;
                    }
                    if (d)
                    {
                        q.push(q.front());
                        q.pop();
                    }
                    else
                    {
                        b[q.front()] = 0;
                        q.pop();
                    }
                }
                q.push(a[j]);
                b[a[j]] = 1;
            }
        }
        while(q.size())
        {
            c[q.front()]++;
            b[q.front()] = 0;
            q.pop();
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
