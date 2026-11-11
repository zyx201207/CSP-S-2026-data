#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _,n,m,d,q;
ll w[500005],dis[505][505];
vector<pair<ll,ll>>a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k,id,t;cin>>k;
        for(int j=1;j<=k;++j){
            cin>>id>>t;
            a[id].push_back({i,t});
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        for(int j=0;j<a[i].size();++j){
            for(int k=j+1;k<a[i].size();++k){
                auto p1=a[i][j];auto p2=a[i][k];
                dis[p2.first][p1.first]=dis[p1.first][p2.first]=min(dis[p1.first][p2.first],p1.second+p2.second);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto p1:a[x]){
            for(auto p2:a[y]){
                ans=min(ans,dis[p1.first][p2.first]+p1.second+p2.second+w[x]+w[y]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}