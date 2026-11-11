#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    vector<int> cnt(m+1);
    for(int i=1;i<=n;++i)
    {
        vector<int> vis(m+1,0);
        vector<int> q;
        vector<int> qq;
        bool f=0;
        for(int j=i;j<=n;++j)
        {
            if(!vis[a[j]])
            {
                q.emplace_back(a[j]);
                vis[a[j]]=1;
            }
            else 
            {
                f=1;
                qq.clear();
                for(int z=0;z<q.size() && q[z]!=a[j];++z)
                {
                    qq.emplace_back(q[z]);
                }
                qq.emplace_back(a[j]);
                q=qq;
            }
        }
        if(!f)
        {
            for(int j=0;j<q.size();++j)
            {
                cnt[q[j]]++;
            }
        }
        else 
        {
            for(int j=0;j<q.size();++j)
            {
                cnt[q[j]]++;
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}