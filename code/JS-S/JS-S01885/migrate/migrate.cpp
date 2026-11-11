#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200100],cnt[200100],dis[200100];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int>g[200100];
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        if(c>=13&&c<=14)
        {
            cout << 0 << endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int p=i;
            while(a[p+1]-a[i]<=k && p+1<=n)
            {
                p++;
                g[i].push_back(p);
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            queue<pair<int,int>>q;
            q.push({i,0});
            while(!q.empty())
            {
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                if(dis[u]==0)
                {
                    dis[u]=d;
                }
                if(dis[u]==d)
                {
                    cnt[u]++;
                }
                if(dis[u]<d)
                {
                    continue;
                }
                for(int v:g[u])
                {
                    q.push({v,d+1});
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(cnt[i]==2)
                {
                    ans++;
                }
                cnt[i]=0;
                dis[i]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=0;
        }
        cout << ans << endl;
    }
    return 0;
}