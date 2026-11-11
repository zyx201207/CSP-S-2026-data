#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,dis[N][N],a[M];
vector<pair<int,int> > bel[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=1844674407370955161;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int ai,ti;
            cin>>ai>>ti;
            for(auto& v:bel[ai])
                dis[i][v.first]=dis[v.first][i]=min(dis[i][v.first],ti+v.second);
            bel[ai].push_back(make_pair(i,ti));
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int st,en;cin>>st>>en;
        int ans=1844674407370955161;
        for(auto& s:bel[st])
            for(auto& e:bel[en])
                ans=min(ans,a[st]+a[en]+s.second+e.second+dis[s.first][e.first]);
        cout<<ans<<'\n';
    }
    return 0;
}
