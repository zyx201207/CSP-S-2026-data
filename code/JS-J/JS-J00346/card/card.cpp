#include <bits/stdc++.h>
using namespace std;
stack <int> s;
int a[500005];
int vis[300005];
int ans[300005];
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int l=n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        memset(vis, 0, sizeof vis);
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]])
            {
                while(s.top() != a[j])
                {
                    vis[s.top()] = 0;
                    s.pop();
                }
                s.pop();
            }
            s.push(a[j]);
            vis[a[j]] = 1;
        }
        int jsq = 0;
        l=s.size();
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
            jsq++;
        }
    }
    for(int i=1;i<=m;i++)
        cout << ans[i] << " ";
    return 0;
}
