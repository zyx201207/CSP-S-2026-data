#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;
const int N=505,M=5e5+10,MAXN=1e12;
int c,n,m,d,q;
int w[M],k[N],t[N][M];
int g[N][N];
vector<int> g2[M];


int read()
{
    int x=0;
    char cc;
    while(!('0'<=cc&&cc<='9')) cc=getchar();
    while('0'<=cc&&cc<='9')
    {
        x=x*10+(int)(cc-'0');
        cc=getchar();
    }
    return x;
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)    g[i][j]=0;
            else    g[i][j]=MAXN;
        }
    }

    for(int i=1;i<=m;i++)   w[i]=read();
    for(int i=1;i<=n;i++)
    {
        k[i]=read();
        for(int j=1,u,v;j<=k[i];j++)
        {
            u=read(),v=read();
            t[i][u]=v;
            g2[u].push_back(i);
            for(int s=1;s<i;s++)
            {
                if(t[s][u]!=0)
                {
                    g[i][s]=min(g[i][s],t[i][u]+t[s][u]);
                    g[s][i]=min(g[s][i],t[i][u]+t[s][u]);
                }
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g[i][j]==MAXN)    cout<<-1<<" ";
            else    cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                        g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    while(q--)
    {
        int x,y,ans=MAXN;
        x=read(),y=read();
        for(int i=0;i<g2[x].size();i++)
        {
            int u=g2[x][i];
            for(int j=0;j<g2[y].size();j++)
            {
                int v=g2[y][j];
                ans=min(ans,t[u][x]+t[v][y]+g[u][v]);
                //cout<<u<<" "<<v<<" | "<<<<t[u][x]<<" "<<t[v][y]<<" "<<g[u][v]<<endl;
            }
        }
        //cout<<endl;
        cout<<(ans+w[x]+w[y])<<endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
