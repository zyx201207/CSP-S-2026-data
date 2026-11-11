#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q;
int w[500005];
int dis[501][501];
vector<pair<int,int> >v[500005];
signed main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int T=1;T<=k;T++){
                int a,t;
                cin>>a>>t;
                for(auto j:v[a]){
                    dis[i][j.first]=dis[j.first][i]=min(dis[i][j.first],t+j.second);
                }
                v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto i:v[x])
            for(auto j:v[y]){
                ans=min(ans,dis[i.first][j.first]+i.second+j.second);
            }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
}

