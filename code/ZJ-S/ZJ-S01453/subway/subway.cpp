#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
inline void cmin(ll&x,const ll y){x=min(x,y);}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _,n,m,d,q;
    cin>>_>>n>>m>>d>>q;
    vector<int> w(m);
    for(int i=0;i<m;i++)cin>>w[i];
    vector<vector<pii>> arr(m);
    for(int u=0;u<n;u++){
        int k;
        cin>>k;
        vector<int> a(k),t(k);
        for(int i=0;i<k;i++){
            cin>>a[i]>>t[i],a[i]--;
            arr[a[i]].emplace_back(u,t[i]);
        }
    }
    vector<vector<ll>> dis(n,vector<ll>(n,1e18));
    for(int i=0;i<n;i++)dis[i][i]=0;
    for(int x=0;x<m;x++){
        const size_t w=arr[x].size();
        for(size_t i=0;i<w;i++){
            auto[u,tu]=arr[x][i];
            for(size_t j=i+1;j<w;j++){
                auto[v,tv]=arr[x][j];
                cmin(dis[u][v],tu+tv);
                cmin(dis[v][u],tu+tv);
            }
        }
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        cmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y,x--,y--;
        ll ans=1e18;
        for(auto[u,tu]:arr[x])for(auto[v,tv]:arr[y]){
            ans=min(ans,dis[u][v]+tu+tv);
        }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}