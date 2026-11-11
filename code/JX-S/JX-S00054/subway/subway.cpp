#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=505;
const int M=500005;
const int K=1000006;
int c,n,m,d,q;
int x,y;
int w[M],k[N];
int dist[N][N];
int head[M],ver[K],nxt[K],edge[K],tot=0;
void add(int s,int t,int w){
    nxt[tot]=head[s];
    head[s]=tot;
    ver[tot]=t;
    edge[tot]=w;
    tot++;
}
void floyd(){
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(head,-1,sizeof(head));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=100000000000000000;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>x>>y;
            add(x,m+i,y);
            add(m+i,x,y);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=head[i];j!=-1;j=nxt[j]){
            for(int k=head[i];k!=-1;k=nxt[k]){
                if(ver[j]==ver[k]){
                    continue;
                }
                dist[ver[j]-m][ver[k]-m]=min(dist[ver[j]-m][ver[k]-m],edge[j]+edge[k]);
                dist[ver[k]-m][ver[j]-m]=dist[ver[k]-m][ver[j]-m];
            }
        }
    }
    floyd();
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        int ans=100000000000000000;
        for(int j=head[x];j!=-1;j=nxt[j]){
            for(int k=head[y];k!=-1;k=nxt[k]){
                ans=min(ans,dist[ver[j]-m][ver[k]-m]+edge[j]+edge[k]);
            }
        }
        // cout<<ans<<" "<<w[x]<<" "<<w[y]<<endl;
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
}
