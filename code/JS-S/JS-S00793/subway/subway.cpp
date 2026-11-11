#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q,w[20005];//w:door to subway time;
struct ti{
    int s[20005];
}sta[20005];
struct line
{
    int num;
    pair<int,int> t[20005];
}k[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i].num);
        for(int j=1;j<=k[i].num;j++)
        {
            scanf("%d%d",&k[i].t[j].second,&k[i].t[j].first);
            k[i].t[j].first<<1;
        }
        for(int j=1;j<=k[i].num;j++)
        {
            for(int cnt=1;cnt<=k[i].num;cnt++)
            {
                if(sta[cnt].s[j])sta[cnt].s[j]=min(sta[cnt].s[j],k[i].t[j].first+k[i].t[cnt].first);
                else sta[cnt].s[j]=k[i].t[j].first+k[i].t[cnt].first;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y,res;
        res+=w[x]+w[y];
        printf("%d\n",res);
    }
    return 0;
}
