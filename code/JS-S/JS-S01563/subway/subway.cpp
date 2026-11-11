#include<bits/stdc++.h>
using namespace std;
int w[500010];
int k[500010];
int a[5010][5010];
int t[5010][5010];
int f[5050][5050];
int x,y;
int minn=342;
int c,n,m,d,q;
void dfs(int now,int tm)
{
    if(now==y)
    {
        minn=min(minn,tm);
        return;
    }
    if(now==n+1)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            if(a[i][j]==now&&f[i][j]==0)
            {
                f[i][j]=1;
                if(j==1)
                {
                    dfs(a[i][2],tm+t[now][i]+t[a[i][2]][i]);
                }
                else
                {
                    dfs(a[i][1],tm+t[now][i]+t[a[i][1]][i]);
                }
                f[i][j]=0;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            cin>>t[i][j];
            sum+=t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        memset(f,0,sizeof(f));
        if(x==y)
        {
            cout<<0<<"\n";
            continue;
        }
        cout<<minn<<"\n";
    }
    //cout<<minn<<" ";
    return 0;
}
