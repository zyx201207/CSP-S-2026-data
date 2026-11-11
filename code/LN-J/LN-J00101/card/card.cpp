#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],flag[300005],ans[300005];
stack <int> q;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    for (int i = 1;i <= n;i++)
    {
        while(!q.empty())
            q.pop();
        memset(flag,0,sizeof(flag));
        for (int j = i;j <= n;j++)
        {
            if (flag[a[j]])
            {
                for (int i = flag[a[j]];i <= q.size();i++)
                {
                    int t = q.top();
                    flag[t] = 0;
                    q.pop();
                }
            }
            q.push(a[j]);
            flag[a[j]] = q.size();
        }
        for (int j = 1;j <= m;j++)
        {
            if (flag[j])
            {
                ans[j]++;
            }
        }
    }
    for (int i = 1;i <= m;i++)
        cout << ans[i] << " ";
}
