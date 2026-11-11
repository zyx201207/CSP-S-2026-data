#include <bits/stdc++.h>
using namespace std;
int a[500005];
int vis[300005];
int cnt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        vector<int> v;
        for (int j = i;j<=n;j++)
        {
            if (vis[a[j]]!=0)
            {
                while (v.size()!=0)
                {
                    if (v[v.size()-1]==a[j]) break;
                    vis[v[v.size()-1]]--;
                    v.pop_back();
                }
            }
            else
            {
                v.push_back(a[j]);
                vis[a[j]]++;
            }
        }
        for (int i = 0;i<v.size();i++)
        {
            cnt[v[i]]++;
        }
    }
    for (int i = 1;i<=m;i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
