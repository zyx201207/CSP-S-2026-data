#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    int a[500005], b[500005];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    stack<int> stk;
    int vis[300005];
    int ans[300005];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        for(int j = 1 + i; j <= n; j++)
        {
            if(vis[a[j]] == 0)
            {
                stk.push(a[j]);
                vis[a[j]] = 1;
            }
            else
            {
                while(stk.top() != a[j])
                {
                    vis[stk.top()] = 0;
                    stk.pop();
                }
                stk.pop();
                stk.push(a[j]);
            }
            /*for(int k = 1; k <= m; k++)
            {
                if(vis[k])
                    cout << k << ' ';
            }
            cout << endl;*/
        }
        while(!stk.empty())
        {
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
