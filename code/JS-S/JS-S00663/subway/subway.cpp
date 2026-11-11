#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;

int c,n,m,d,q;
int w[M];
int dis[N][N];
struct Node{
    int l,t;//line time
};
vector<Node>v[M];

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            v[a].push_back(Node{i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(Node dx:v[i]){
            for(Node dy:v[i]){
                int x=dx.l,y=dy.l;
                if(x==y)
                    continue;
                dis[x][y]=dis[y][x]=min(dis[x][y],dx.t+dy.t);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(Node dx:v[x])
            for(Node dy:v[y])
                ans=min(ans,dx.t+dy.t+dis[dx.l][dy.l]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}