#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
#define forDown(i,a,b) for(int i=(a);i>=(b);--i)
#define pushb push_back
using int64=long long;constexpr int64 INF64=0x3f3f3f3f3f3f3f3f;
constexpr int N=500+10,M=5e5+10;int task_id;using namespace std;
int n,m,d,q,A[M];vector<array<int,2>> G[M];
int64 dis[N][N];
void solve(int test_id){
    cin>>n>>m>>d>>q;
    forUp(v,1,m)cin>>A[v];
    forUp(u,1,n){
        int k;cin>>k;
        while(k--){
            int v,w;cin>>v>>w;
            G[v].pushb({u,w});
        }
    }
    forUp(u,1,n)forUp(v,1,n)dis[u][v]=u==v?0:INF64;
    forUp(v,1,m){
        int sz=G[v].size();
        forUP(i,0,sz)forUP(j,0,sz){
            int u1=G[v][i][0],w1=G[v][i][1];
            int u2=G[v][j][0],w2=G[v][j][1];
            dis[u1][u2]=min(dis[u1][u2],(int64)w1+w2);
        }
    }
    forUp(w,1,n)forUp(u,1,n)forUp(v,1,n)dis[u][v]=min(dis[u][v],dis[u][w]+dis[w][v]);
    while(q--){
        int v1,v2;cin>>v1>>v2;int64 ans=INF64;
        for(auto e1:G[v1])for(auto e2:G[v2]){
            int u1=e1[0],w1=e1[1];
            int u2=e2[0],w2=e2[1];
            ans=min(ans,w1+dis[u1][u2]+w2);
        }
        ans+=A[v1]+A[v2];
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int test_num=1,tst=clock();
    cin>>task_id;
    //cin>>test_num;
    forUp(test_id,1,test_num)solve(test_id);
    cerr<<1000.0*(clock()-tst)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}