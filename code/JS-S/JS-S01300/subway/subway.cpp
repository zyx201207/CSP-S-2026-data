#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct bb
{
    int to,v;
};
int w[500005];
vector<bb> tu[500005];
long long tt[505][505];
int k,a,t;
int x,y;
long long summ;
long long llmax=50;
void sh()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                tt[i][j]=tt[j][i]=min(tt[i][j],tt[i][k]+tt[k][j]);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=16;i++) llmax*=10;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        bb getin;
        getin.to=i;
        for(int j=1;j<=k;j++)
        {
            scanf("%d%d",&a,&t);
            getin.v=t;
            tu[a].push_back(getin);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++) tt[i][j]=llmax;

        for(int j=i+1;j<=n;j++) tt[i][j]=llmax;
        tt[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int ki=0;ki<tu[i].size();ki++)
        {
            for(int kj=0;kj<tu[i].size();kj++)
            {
                tt[tu[i][ki].to][tu[i][kj].to]=tt[tu[i][kj].to][tu[i][ki].to]=min(tt[tu[i][ki].to][tu[i][kj].to],(long long)tu[i][ki].v+(long long)tu[i][kj].v);
            }
        }
    }
    sh();
    llmax*=2;
    for(int i=1;i<=q;i++)
    {
        summ=llmax;
        scanf("%d%d",&x,&y);
        for(int ki=0;ki<tu[x].size();ki++)
        {
            for(int kj=0;kj<tu[y].size();kj++)
            {
                summ=min(summ,(long long)tu[x][ki].v+(long long)tu[y][kj].v+tt[tu[x][ki].to][tu[y][kj].to]);
            }
        }
        summ+=w[x]+w[y];
        printf("%lld\n",summ);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
