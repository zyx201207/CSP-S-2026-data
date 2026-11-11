#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
int c,n,m,d,q;
long long a[500005];
long long w[550][550];
int kl[550];
vector<pair<int,long long>> va[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&kl[i]);
        for(int j=1;j<=kl[i];j++)
        {
            int s;
            long long t;
            scanf("%d%lld",&s,&t);
            va[s].push_back(make_pair(i,t));
        }
    }
    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=n;i++)
    {
        w[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        if(va[i].size()<=1)
        {
            continue;
        }
        for(int j=0;j<va[i].size()-1;j++)
        {
            for(int k=j+1;k<va[i].size();k++)
            {
                w[va[i][j].first][va[i][k].first]=min(w[va[i][j].first][va[i][k].first],va[i][j].second+va[i][k].second);
                w[va[i][k].first][va[i][j].first]=min(w[va[i][k].first][va[i][j].first],va[i][j].second+va[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    for(int qu=1;qu<=q;qu++)
    {
        int st,ed;
        scanf("%d%d",&st,&ed);
        long long anss=1e18;
        for(int i=0;i<va[st].size();i++)
        {
            for(int j=0;j<va[ed].size();j++)
            {
                anss=min(anss,va[st][i].second+va[ed][j].second+w[va[st][i].first][va[ed][j].first]);
            }
        }
        anss=anss+a[st]+a[ed];
        printf("%lld\n",anss);
    }
    return 0;
}
