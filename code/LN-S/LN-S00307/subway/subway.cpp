#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[3000];
long long dp[3000][3000];
long long mj(int x,int y)
{
    if(dp[x][y]!=0)
    {
        return dp[x][y];
    }
    for(int i=1;i<=m;i++)
    {
        if(i==x || i==y)
        {
            dp[x][y]=0;
        }
        else
        {
            if(dp[x][y]!=0)
            {
                dp[x][y]=min(dp[x][y],mj(x,i)+mj(i,y));
            }
            else
            {
                dp[x][y]=mj(x,i)+mj(i,y);
            }
        }
        dp[y][x]=dp[x][y];
    }
    return dp[x][y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        //cin>>w[i];
    }
    int tik;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        long long xx,yy;
        cin>>tik;
        if(tik==2)
        {
            cin>>x>>xx>>y>>yy;
            if(dp[x][y]>0)
            {
                dp[x][y]=min(dp[x][y],xx+yy);
                dp[y][x]=min(dp[x][y],xx+yy);
            }
            else
            {
                dp[x][y]=xx+yy;
                dp[y][x]=xx+yy;
            }

        }
    }
    for(int i=1;i<=q;i++)
    {
        int st,en;
        cin>>st>>en;
        long long jkl=mj(st,en);
        cout<<jkl+w[st]+w[en];
    }
    return 0;
}
