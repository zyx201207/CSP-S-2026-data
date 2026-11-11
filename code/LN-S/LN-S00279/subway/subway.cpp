#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,t[501][500001],a,w1,w2,n1[501][501],w[500001],tu[500001];
void suan(int x,int y)
{
    int ans=0,n2=0,n3=0;
    for(int j=1;j<=n;j++)
    {
        if(t[j][x]>0)
        {
            n2=j;
            break;
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(t[j][y]>0)
        {
            n3=j;
            break;
        }
    }
    if(n2==n3) ans=0;
    else
    {
        if(n1[n2][n3]>0) ans=n1[n2][n3];
    }
    ans+=w[x]+w[y]+t[n2][x]+t[n3][y];
    printf("%d\n",ans);
}
void initial(int x)
{
    int o[501],p=1;
    for(int i=1;i<=n;i++)
    {
        if(t[i][x]>0)
        {
            o[i]=i;
            p++;
        }
    }
    p--;
    for(int i=p;i>=1;i--)
    {
        for(int j=p-1;j>=1;j--)
        {
            n1[o[i]][o[j]]=max(n1[o[i]][o[j]],t[o[i]][x]+t[o[j]][x]);
            n1[o[j]][o[i]]=max(n1[o[j]][o[i]],t[o[i]][x]+t[o[j]][x]);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&a);
            tu[a]++;
            scanf("%d",&t[i][a]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(tu[i]>1)
        {
            initial(i);
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d",&w1,&w2);
        suan(w1,w2);
    }
    return 0;
}
