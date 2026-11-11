#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int c,n,m,d,q;
int w[N];
int flo[N][N];
void small()
{
    memset(flo,0x3f,sizeof(flo));
    for(int i=1;i<=n+m;i++) flo[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int ki;
        scanf("%lld",&ki);
        for(int k=1;k<=ki;k++)
        {
            int station;
            scanf("%lld",&station);
            int cost;
            scanf("%lld",&cost);
            flo[station][m+i]=cost;
            flo[m+i][station]=cost;
        }
    }
    for(int mid=1;mid<=m+n;mid++)
    {
        for(int s=1;s<=m+n;s++)
        {
            for(int e=1;e<=m+n;e++)
            {
                flo[s][e]=min(flo[s][e],flo[s][mid]+flo[mid][e]);
            }
        }
    }
    // for(int s=1;s<=m+n;s++)
    // {
    //     for(int e=1;e<=m+n;e++)
    //     {
    //         printf("%lld ",flo[s][e]);
    //     }
    //     puts("");
    // }
    for(int i=1;i<=q;i++)
    {
        int f,t;
        scanf("%lld%lld",&f,&t);
        printf("%lld\n",w[f]+w[t]+flo[f][t]);
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    if(n+m<=505) small();
    return 0;
}
