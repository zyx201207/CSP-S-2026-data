#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        queue<int> q = {};
        bool mark[300005] = {};
        for(int j = i;j <= n;j++)
        {
            if(mark[a[j]])
            {
                while(true)
                {
                    if(q.front()==a[j])
                    {
                        q.pop();
                        break;
                    }
                    q.pop();
                }
                q.push(a[j]);
            }
            else
            {
                q.push(a[j]);
            }
        }
        for(int j = 1;j <= q.size();j++)
        {
            ans[q.front()]++;
            q.pop();
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
