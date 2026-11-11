#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=5e5+5,N=505;
const ll inf=1e18;
int cc,n,m,dd,q;
vector<pii>v[M];
ll tt[M],f[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>cc>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++)
        cin>>tt[i];
    for(int i=1;i<=n;i++)
    {
        int num;cin>>num;
        for(int j=1;j<=num;j++)
        {
            int x,w;cin>>x>>w;
            v[x].push_back(make_pair(i,w));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=inf;
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto l:v[i])
        {
            for(auto r:v[i])
            {
                ll num=l.second+r.second;
                f[l.first][r.first]=min(f[l.first][r.first],num);
                f[r.first][l.first]=min(f[r.first][l.first],num);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        ll ans=1e18;
        for(auto x:v[l])
            for(auto y:v[r])
                ans=min(ans,f[x.first][y.first]+(ll)x.second+(ll)y.second);
        ans+=tt[l]+tt[r];
        cout<<ans<<"\n";
    }
    return 0;
}
