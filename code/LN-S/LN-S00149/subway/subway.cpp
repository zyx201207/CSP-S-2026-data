#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=555;//lines cnt maxx
const int maxm=5e5+5;//node cnt maxx

struct node{
    //informations
    //this node to a line    
    int y;//which line
    int w;//cost how much time
};
vector <node> g[maxm];
int k[maxm],w[maxm];
int dis[maxn][maxn];
int aa,tt;
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    //cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
        //cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        //cin>>k[i];
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&aa,&tt);
            //cin>>aa>>tt;
            g[aa].push_back({i,tt});
        }
    }


    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto u:g[i]){
            for(auto v:g[i]){
                if(u.y==v.y) continue;
                dis[u.y][v.y]=u.w+v.w;
            }
        }
    }
    for(int kk=1;kk<=n;kk++){
        for(int ii=1;ii<=n;ii++){
            for(int jj=1;jj<=n;jj++){
                dis[ii][jj]=min(dis[ii][jj],dis[ii][kk]+dis[kk][jj]);
            }
        }
    }
    int x,y,ans,now;
    while(q--){
        ans=1000000000000000000;
        scanf("%lld%lld",&x,&y);
        //cin>>x>>y;
        for(auto u:g[x]){
            for(auto v:g[y]){
                now=w[x]+w[y]+u.w+v.w+dis[u.y][v.y];
                ans=min(ans,now);
            }
        }
        printf("%lld\n",ans);
        // cout<<ans<<endl;
    }
    


    return 0;
}