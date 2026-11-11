#include<bits/stdc++.h>
using namespace std;
const int N=60,M=310,INF=1e9;
int c,n,m,d,q;
int k;
int node[N][M];
int w[N],lin[N],t[N][M];
int s1,s2;
int ans;
int res[N],idx;
void dfs(int sx,int sy,int ex,int ey,int tt)
{
    if(sx==ex && sy==ey )
    {
        res[++idx]=tt;
        return ;
    }
    if(sx==sy)
    {
        tt=t[ex][ey];
        dfs(ex,ey,ex,ey,tt);
    }
    for(int i=1;i<=lin[sx];i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=lin[x];y++)
                if(x!=sx && node[x][y]==node[sx][i])
                    dfs(x,y,ex,ey,tt+t[sx][i]+t[x][y]);
}
int main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        lin[i]=k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            node[i][j]=x,t[i][j]=y;
        }
    }
    while(q--)
    {
        memset(res,INF,sizeof res);
        ans=0;
        cin>>s1>>s2;
        if(s1==s2)
        {
            puts("0");
            return 0;
        }
        ans=ans+w[s1]+w[s2];
        int sx,sy,ex,ey;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=lin[i];j++)
                for(int ii=1;ii<=n;ii++)
                    for(int jj=1;jj<=lin[ii];jj++)
                        if(node[i][j]==s1 && node[ii][jj]==s2)
                            dfs(i,j,ii,jj,ans+t[i][j]+t[ii][jj]);
        sort(res+1,res+idx+1);
        cout<<res[1]<<'\n';
    }
    return 0;
}
