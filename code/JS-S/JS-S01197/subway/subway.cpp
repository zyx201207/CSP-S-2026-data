#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,s[500010],x[500010],hc[550][550];
struct station
{
    int a,t;
};
station line[550][50010];
vector<station>st[500010];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
        scanf("%lld",&x[i]);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&s[i]);
        for(int j=1;j<=s[i];++j)
        {
            scanf("%lld%lld",&line[i][j].a,&line[i][j].t);
            st[line[i][j].a].push_back({i,line[i][j].t});
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i==j)hc[i][j]=0;
            else hc[i][j]=1e18;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=s[i];++j)
            for(int k=j+1;k<=s[i];++k)
            {
                int st1=line[i][j].a,st2=line[i][k].a;
                for(auto sa:st[st1])
                    for(auto sb:st[st2])
                    {
                        hc[sa.a][i]=hc[i][sa.a]=min(hc[i][sa.a],line[i][j].t+sa.t);
                        hc[sb.a][i]=hc[i][sb.a]=min(hc[i][sb.a],line[i][k].t+sb.t);
                    }
            }
    }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            for(int k=1;k<=n;++k)
                hc[i][j]=hc[j][i]=min(hc[i][j],hc[i][k]+hc[k][j]);
    while(q--)
    {
        int sa,sb,ans=1e18;
        scanf("%lld%lld",&sa,&sb);
        for(auto i:st[sa])
            for(auto j:st[sb])
                ans=min(ans,i.t+j.t+hc[i.a][j.a]);
        printf("%lld\n",ans+x[sa]+x[sb]);
    }
    return 0;
}
