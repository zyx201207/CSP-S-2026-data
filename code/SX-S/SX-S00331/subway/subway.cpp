#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],ax[505][505];
struct edge{
    long long v,w;
};
edge ct[500005][25];
long long read()
{
    long long ans=0;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++)
    {
        w[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ax[i][j]=0x7f7f7f7f7f7f7f7f;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        k=read();
        for(int j=1;j<=k;j++)
        {
            long long a,t;
            a=read();
            t=read();
            for(int kx=1;kx<=ct[a][0].w;kx++)
            {
                long long v=ct[a][kx].v,w=ct[a][kx].w;
                ax[i][v]=min(ax[i][v],t+w);
                ax[v][i]=min(ax[v][i],t+w);
            }
            ct[a][0].w++;
            ct[a][ct[a][0].w]={i,t};
        }
    }//5e5*20=1e7
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            if(k==i)
            {
                ax[i][k]=ax[k][i]=0;
                continue;
            }
            for(int j=1;j<=n;j++)
            {
                if(i==j||k==j)
                {
                    continue;
                }
                ax[i][j]=min(ax[i][j],ax[i][k]+ax[k][j]);
            }
        }
    }//>1e8
    int l,r;
    for(int i=1;i<=q;i++)
    {
        // scanf("%d%d",&l,&r);
        l=read();
        r=read();
        long long ans=LLONG_MAX;
        for(int j=1;j<=ct[l][0].w;j++)
        {
            long long v=ct[l][j].v,w=ct[l][j].w;
            if(w>=ans)
            {
                continue;
            }
            for(int k=1;k<=ct[r][0].w;k++)
            {
                long long v2=ct[r][k].v,w2=ct[r][k].w;
                if(w2>=ans)
                {
                    continue;
                }
                ans=min(ans,min(ax[v][v2],ax[v2][v])+w+w2);
            }
        }
        printf("%lld\n",ans+w[l]+w[r]);
    }//1e5*20*20=4e7
    return 0;
}

/*

15:12          严肃开考T2（享受vscode）
17:45          电脑死机约10min+无效烧烤（？）min,疯狂卡常20-30min,终于拿下T2  大概200pts离场，力竭了……

*/