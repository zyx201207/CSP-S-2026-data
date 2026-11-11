#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c,n,m,d,q;
int f[505][505],W[500005];
struct node
{
    int id,w;
};
vector<node>a[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>W[i];
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int v,w;cin>>v>>w;a[v].push_back((node){i,w});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto xx:a[i])
        {
            for(auto yy:a[i])
            {
                if(xx.id==yy.id)
                {
                    continue;
                }
                f[xx.id][yy.id]=min(f[xx.id][yy.id],xx.w+yy.w);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;cin>>x>>y;
        if(x==y)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=1e18;
        for(auto xx:a[x])
        {
            for(auto yy:a[y])
            {
                ans=min(ans,f[xx.id][yy.id]+W[x]+W[y]+xx.w+yy.w);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
