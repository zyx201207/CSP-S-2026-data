#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    unsigned int node[n][m];//时间【线路】【站】
    memset(node,0,sizeof(node));
    unsigned int w[m];
    unsigned int dp[m][m];//i站到j站
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++)scanf("%ud",&w[i]);
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        int tmp;
        for(int j=0;j<t;j++)
        {
            scanf("%d",&tmp);
            scanf("%ud",&node[i][tmp]);
        }
    }
    for(int i=0;i<n;i++)//线路
    {
        for(int j=0;j<m;j++)//站点
        {

            if(node[i][j])
            {
                for(int k=j+1;k<m;k++)
                {
                    if(k<m&&node[i][k]!=0)
                    {
                        dp[j][k]=min(dp[j][k],node[i][j]+node[i][k]);
                        dp[k][j]=min(dp[k][j],node[i][j]+node[i][k]);
                    }
                }
            }
        }
    }
    bool ok=true;
    while(ok)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]+1)
                {
                    for(int k=0;k<m;k++)
                    {
                        if(dp[j][k]+1)
                        {
                            dp[i][k]=min(dp[i][k],dp[i][j]+dp[j][k]);
                            //cout<<dp[i][k];
                        }
                    }
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]+1==0)ok=true;
            }
        }
        if(ok)break;
    }

    while(q--)
    {
        int first,last;
        scanf("%d%d",&first,&last);
        printf("%d\n",dp[first][last]+w[first]+w[last]);
    }
    return 0;
}
