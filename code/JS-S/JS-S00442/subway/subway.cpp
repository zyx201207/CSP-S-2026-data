#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
unsigned int v[500010][510];
vector<int>gone[510];
vector<int>have[500010];
unsigned int road[510][510];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a[500010],t[500010];
            cin>>a[i]>>t[i];
            v[a[i]][i]=t[i];
            have[a[i]].push_back(i);
            gone[i].push_back(a[i]);
        }
    }
    memset(road+1,0x3f,sizeof road);
    for(int i=1;i<=n;i++)road[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j:gone[i])
        {
            for(int k:have[j])
            {
                if(k==i)continue;
                road[i][k]=min(road[i][k],v[j][i]+v[j][k]),road[k][i]=min(road[k][i],v[j][i]+v[j][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)road[i][j]=min(road[i][j],road[i][k]+road[k][j]);
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<0<<' ';
            continue;
        }
        unsigned int minn=10000000000000;
        for(int i:have[x])
        {
            for(int j:have[y])
            {
                minn=min(road[i][j]+v[x][i]+v[y][j],minn);
            }
        }
        cout<<w[x]+w[y]+minn<<' ';
    }
    return 0;
}
