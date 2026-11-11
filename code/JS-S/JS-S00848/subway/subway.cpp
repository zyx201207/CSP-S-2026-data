#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,d1[1010],d2[1010][30],l[1010][1010],sum[1010],s,t,dp[1010][1010];
struct node
{
    int sl,pos;
};
vector<node>vt[1010];
void dfs(int x,int y,int sm,int qd)
{
    if(sm>=dp[qd][y]&&qd!=y) return ;
    dp[qd][y]=dp[y][qd]=sm;
    for(int i=0;i<vt[y].size();i++)
    {
        int t1=vt[y][i].sl,t2=vt[y][i].pos;
        for(int j=1;j<=sum[t1];j++)
            if(l[t1][j]!=qd)dfs(t1,l[t1][j],sm+d2[y][t1]+d2[l[t1][j]][t1],qd);
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&d1[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&sum[i]);
        for(int j=1;j<=sum[i];j++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            l[i][j]=a,d2[a][i]=b;
            vt[a].push_back((node){i,j});
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++)
    {
        dp[i][i]=0;
        dfs(0,i,0,i);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&s,&t);
        printf("%d\n",dp[s][t]+d1[s]+d1[t]);
    }
    return 0;
}
