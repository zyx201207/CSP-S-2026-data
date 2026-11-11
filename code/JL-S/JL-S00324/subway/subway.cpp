#include<bits/stdc++.h>
#define int long long
#define len (i-j+1)
using namespace std;
int c,n,m,d,q;
int w[1000000],ma[800][800];
struct Point
{
    int to,t,nxt;
}p[1000000];
int hed[1000000],cnt;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i!=j)
            ma[i][j]=LONG_LONG_MAX/5;
    }
    for(int i=1,k;i<=n;i++)
    {
        scanf("%lld",&k);
        //cout<<i<<"{"<<k<<"---"<<endl;
        for(int j=1,x,ta,tt;j<=k;j++)
        {
            scanf("%lld%lld",&ta,&tt);
            //cout<<i<<":"<<ta<<" "<<tt<<endl;
            for(int ff=hed[ta];ff;ff=p[ff].nxt)
            {
                ma[i][p[ff].to]=min(ma[i][p[ff].to],tt+p[ff].t);
                ma[p[ff].to][i]=min(ma[p[ff].to][i],tt+p[ff].t);
            }
            p[++cnt]={i,tt,hed[ta]},hed[ta]=cnt;
        }
    }
    /*for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {
            cout<<ma[i][j];
        }
        cout<<endl;
    }*/
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
        }
    while(q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int ans=LONG_LONG_MAX;
        for(int ff=hed[x];ff;ff=p[ff].nxt)
        {
            int linex=p[ff].to;
            for(int gg=hed[y];gg;gg=p[gg].nxt)
            {
                int liney=p[gg].to;
                ans=min(ans,p[ff].t+p[gg].t+ma[linex][liney]);

            }
        }
        printf("%lld\n",w[x]+w[y]+ans);
    }
    return 0;
}

