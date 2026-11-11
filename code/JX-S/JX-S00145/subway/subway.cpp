#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500010];
ll f[510][510];
vector <pair<ll,int> > AT[500010];
void solve()
{
    int n,m,d,q;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    memset(f,0x3f3f3f3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a;
            ll t;
            cin>>a>>t;
            AT[a].push_back({t,i});
        }
        f[i][i]=0;
    }
    for(int x=1;x<=m;x++)
    {
        for(int i=0;i<AT[x].size();i++)
        {
            for(int j=i+1;j<AT[x].size();j++)
            {
                ll ti=AT[x][i].first;
                ll tj=AT[x][j].first;
                int idi=AT[x][i].second;
                int idj=AT[x][j].second;
                f[idi][idj]=min(f[idi][idj],ti+tj);
                f[idj][idi]=min(f[idj][idi],ti+tj);
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
    for(int cc=1;cc<=q;cc++)
    {
        int x,y;
        cin>>x>>y;
        ll ans=LLONG_MAX;
        for(auto i:AT[x])
        {
            for(auto j:AT[y])
            {
                ans=min(ans,i.first+j.first+f[i.second][j.second]);
            }
        }
        cout<<w[x]+w[y]+ans<<"\n";
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testc;
    cin>>testc;
    solve();
    return 0;
}
