#include<bits/stdc++.h>
using namespace std;
using i64=long long;

const int N=510,maxn=5e5+10;
const i64 inf=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
int w[maxn];
i64 dp[N][N];

struct node{
    int v; i64 w;
};
vector<node> vec[maxn];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,u,w;j<=k;j++){
            cin>>u>>w;
            vec[u].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dp[i][j]=inf;
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int cur=1;cur<=m;cur++){ 
        for(int i=0;i<vec[cur].size();i++){
            for(int j=0;j<vec[cur].size();j++){
                if(i==j) continue;
                i64 w=vec[cur][i].w+vec[cur][j].w;
                int u=vec[cur][i].v,v=vec[cur][j].v;
                if(u>v) swap(u,v);
                dp[u][v]=min(dp[u][v],w);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=i+1;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    while(q--){
        int x,y; cin>>x>>y;
        i64 ans=inf;
        for(int i=0;i<vec[x].size();i++)
            for(int j=0;j<vec[y].size();j++){
                int u=vec[x][i].v,v=vec[y][j].v;
                if(u>v) swap(u,v);
                ans=min(ans,dp[u][v]+vec[x][i].w+vec[y][j].w);
            }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}