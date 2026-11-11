#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,x,y,s,ans;//c编号、n线路数<=500、m站数<=500000、d最多几条线路经过,q计划数
ll w[500001],k[501],a[501][500001],t[500001][501];
vector<ll> side[20005];
int step[20005][20005];

int zsx(int now,int last)
{
    if(now==y)return ans;

    step[last][now]=1;
    step[now][last]=1;
    if(last>m)ans+=t[now][last-m];
    else ans+=t[last][now-m];

    for(int i=0;i<(int)side[now].size();++i)
    {
        if(!step[now][(int)side[now][i]])
        {
            zsx((int)side[now][i],now);
        }

    }
}
int main()
{
    std::cin.tie(0);std::cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];++j)
        {
            cin>>a[i][j]>>t[i][j];
            side[m+i].push_back(a[i][j]);
            side[a[i][j]].push_back(m+i);
        }
    }
    while(q--)
    {ans=0;
        cin>>x>>y;
        ans+=w[x]+w[y];
        cout<<zsx(x,0)<<"\n";
    }
    return 0;
}
