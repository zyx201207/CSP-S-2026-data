#include<bits/stdc++.h>
#define maxm 500005
#define maxn 505
#define inf 100000000000000017ll
using namespace std;
int c,n,m,d,q;
long long w[maxm];
vector<long long> t[maxm];
vector<int> bel[maxm];
int k[maxn],l[maxm];
long long f[maxn][maxn];
int read()
{
    char xx=getchar();
    int tot=0,f=1;
    while(xx<'0'||xx>'9')
    {
        if(xx=='-')
        {
            f=-1;
        }
        xx=getchar();
    }
    while(xx>='0'&&xx<='9')
    {
        tot=tot*10+xx-'0';
        xx=getchar();
    }
    return tot*f;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)
    {
        w[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        k[i]=read();
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            x=read();y=read();
            bel[x].push_back(i);
            t[x].push_back(y);
            l[x]++;
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<l[i];j++)
        {
            for(int k=j+1;k<l[i];k++)
            {
                int x=bel[i][j],y=bel[i][k];
                f[x][y]=f[y][x]=min(f[x][y],t[i][j]+t[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==k)
            {
                continue;
            }
            for(int j=1;j<=n;j++)
            {
                if(i==j||k==j)
                {
                    continue;
                }
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    while(q--)
    {
        int x,y;
        long long ans=inf;
        x=read();y=read();
        for(int i=0;i<l[x];i++)
        {
            for(int j=0;j<l[y];j++)
            {
                ans=min(t[x][i]+t[y][j]+f[bel[x][i]][bel[y][j]],ans);
            }
        }
        //cout<<ans<<"\n";
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
