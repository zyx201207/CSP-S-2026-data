#include<bits/stdc++.h>
using namespace std;
#define N 510
#define K 500010
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3fll
struct node{
    int x,t;
};
int w[K];
vector<node> a[K];
LL dis[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int aa,t;
            cin>>aa>>t;
            a[aa].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int x=a[i].size();
        for(int j=0;j<x-1;j++){
            for(int k=j+1;k<x;k++){
                node n1=a[i][j],n2=a[i][k];
                dis[n1.x][n2.x]=dis[n2.x][n1.x]=min(dis[n2.x][n1.x],(LL)n1.t+n2.t);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        LL ans=INF;
        int n1=a[x].size(),n2=a[y].size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                ans=min(ans,(LL)dis[a[x][i].x][a[y][j].x]+a[x][i].t+a[y][j].t);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
