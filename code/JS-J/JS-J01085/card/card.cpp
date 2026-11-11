#include <bits/stdc++.h>

using namespace std;

int n,m;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> a(2*n+1);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    vector<int> ans(m+1,0);

    for (int i=1;i<=n;i++)//第i局
    {
        int sum;
        vector<int> vis(m+1,0);
        vector<int> o(m+1,0);
        queue<int> q;
        int x=0;
        for (int j=i;j<=n;j++)
        {
            if(vis[j])
            {
                for (int k=vis[j];k<=x;k++)
                {
                    vis[o[k]]=0;
                    q.push(o[k]);
                    o[k]=0;
                }
            }
            else
            {
                x++;
                vis[j]=x;
                o[x]=a[j];
            }
        }
        sum=i-1+q.size();
        for (int j=1;j<=sum;j++)
        {
            a[j]=q.front();
            q.pop();
        }
        for (int j=1;j<=m;j++)
        {
            if(vis[j])
            {
                ans[j]++;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
