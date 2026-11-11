#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],dist[505][505];
vector<pair<ll,ll>>vec[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(dist,0x3f,sizeof dist);
    ll MAXN=dist[0][0];
    for(ll i=1;i<=n;i++)dist[i][i]=0;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll K;
        cin>>K;
        for(ll j=1;j<=K;j++){
            ll a,t;
            cin>>a>>t;
            if(vec[a].size()>0)
                for(ll k=0;k<vec[a].size();k++)
                    dist[vec[a][k].first][i]=dist[i][vec[a][k].first]=min(dist[vec[a][k].first][i],t+vec[a][k].second);
            vec[a].push_back({i,t});
        }
    }
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                if(dist[i][k]!=MAXN&&dist[k][j]!=MAXN&&dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=MAXN;
        for(pair<ll,ll>i:vec[x])
            for(pair<ll,ll>j:vec[y])
                ans=min(ans,dist[i.first][j.first]+i.second+j.second);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
