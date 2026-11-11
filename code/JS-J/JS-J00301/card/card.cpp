#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    queue<int>q;
    long long n,m,a[500005]={},p[300005]={},ans[300005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) p[j]=0;
        for(int j=i;j<=n;j++)
        {
            if(!p[a[j]])
            {
                q.push(a[j]);
                p[a[j]]=1;
            }
            else
            {
                while(!q.empty())
                {
                    p[q.front()]=0;
                    q.pop();
                }
                q.push(a[j]);
                p[a[j]]=1;
            }
        }
        while(!q.empty())
        {
            ans[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
