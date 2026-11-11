#include<iostream>
#include<vector>

#define int long long

using namespace std;

const int inf=1e18;

static inline void chkmin(int &x,int y){if(x>y)x=y;}

int n,m,D,q;
int a[500005];

struct node{
    int p,t;
};
vector<node>vec[500005];

int dis[505][505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _id;
    cin>>_id>>n>>m>>D>>q;
    for(int i=1;i<=m;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int p,t;
            cin>>p>>t;
            vec[p].push_back({i,t});
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            dis[i][j]=inf;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;++i)
        for(auto v1:vec[i])
            for(auto v2:vec[i])
                if(v1.p!=v2.p)
                    chkmin(dis[v1.p][v2.p],v1.t+v2.t);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                chkmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(auto v1:vec[x])
            for(auto v2:vec[y])
                ans=min(ans,v1.t+v2.t+dis[v1.p][v2.p]);
        cout<<ans+a[x]+a[y]<<'\n';
    }
    return 0;
}