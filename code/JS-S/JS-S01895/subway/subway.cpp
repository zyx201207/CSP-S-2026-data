#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,q;
ll m,n,d,w[500005],k[505],sum_k[505],T;
vector<ll>a[505];
vector<ll>t[505];
ll G[5005][5005];
bool special_A,special_B;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        if(k[i]>2)
            special_A=true;
        sum_k[i]=sum_k[i-1]+k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1,x;j<=k[i];j++)
        {
            cin>>x;
            a[i].push_back(x);
            cin>>x;
            if(T==0)
                T=x;
            if(x!=T)
                special_B=true;
            t[i].push_back(x);
        }
    }
    memset(G,0x3f,sizeof G);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
            G[m+sum_k[i-1]+j][a[i][j]]=G[a[i][j]][m+sum_k[i-1]+j]=t[i][j];
        for(int j=2;j<=k[i];j++)
            G[m+sum_k[i-1]+j][m+sum_k[i-1]+j-1]=G[m+sum_k[i-1]+j-1][m+sum_k[i-1]+j]=0;
    }
    for(int k1=1;k1<=m+sum_k[n];k1++)
        for(int i=1;i<=m+sum_k[n];i++)
            for(int j=1;j<=m+sum_k[n];j++)
                G[i][j]=min(G[i][k1]+G[k1][j],G[i][j]);
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<G[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
