#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int M=5e5+10;
const long long INF=1e18;
int n,m;
int c;
int d;
int q;
struct Vector{
    long long u[22];
    long long w[22];
    int tot=0;
    void push_back(int x,long long y){
        u[++tot]=x;
        w[tot]=y;
    }
};
Vector have[M];
long long k[N];
long long w[M];
long long dist[N][N];
long long min_dis[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        min_dis[i]=INF;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            long long x;
            long long y;
            cin>>x>>y;
            have[x].push_back(i,y);
            min_dis[i]=min(min_dis[i],y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dist[i][j]=INF;
        }
        dist[i][i]=0;
    }
    if(n==1){
        dist[1][1]=0;
    }
    else if(n==2){
        dist[1][2]=dist[2][1]=min_dis[1]+min_dis[2];
    }
    else{
        for(int i=1;i<=m;i++){
            for(int U=1;U<=have[i].tot;U++){
                for(int V=U;V<=have[i].tot;V++){
                    long long u=have[i].u[U];
                    long long v=have[i].u[V];
                    long long w1=have[i].w[U];
                    long long w2=have[i].w[V];
                    dist[u][v]=min(dist[u][v],w1+w2);
                    dist[v][u]=min(dist[v][u],w1+w2);
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=INF;
        for(int U=1;U<=have[x].tot;U++){
            for(int V=U;V<=have[y].tot;V++){
                long long u=have[x].u[U];
                long long v=have[y].u[V];
                long long w1=have[x].w[U];
                long long w2=have[y].w[V];
                ans=min(ans,w[x]+w[y]+w1+w2+dist[u][v]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}