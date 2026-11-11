#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],vis[500005],ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        stack<int> s;
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]])
            {
                while(!s.empty()&&s.top()!=a[j])
                {
                    s.pop();
                }
                if(!s.empty())s.pop();
            }
            s.push(a[j]);
            vis[a[j]]=1;
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
