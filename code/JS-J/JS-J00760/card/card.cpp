#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        queue<long long> q;
        bool vis[500005];
        long long d[500005];
        memset(vis,false,sizeof(vis));
        for(long long j=i;j<=n;j++)
        {
            if(vis[a[j]]==true)
            {
                queue<long long> q2;
                for(long long k=1;k<d[a[j]];k++)
                {
                    q2.push(q.front());
                    q.pop();
                }
                while(!q.empty())
                {
                    q.pop();
                }
                while(!q2.empty())
                {
                    q.push(q2.front());
                    q2.pop();
                }
            }
            q.push(a[j]);
            d[a[j]]=j;
            vis[a[j]]=true;
        }
        while(!q.empty())
        {
            ans[q.front()]++;
            cout<<ans[q.front()];
            q.pop();
        }
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
