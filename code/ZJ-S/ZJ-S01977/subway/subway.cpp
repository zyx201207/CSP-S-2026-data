#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=5e5+5;
int n,m,d,t[M];
// vector<int> a[505],b[505];
int h[M+N],cnte;
int f[N+M],tot=0;
struct E{int t,nxt,w;}e[N+M*2];
void add(int u,int v,int w){
    e[++cnte].nxt=h[u];
    e[cnte].t=v;
    e[cnte].w=w;
    h[u]=cnte;
}
//注意到每个车站最多被20条线路经过。
priority_queue<pair<int,int> > q;
void dijk(int st){
    q.push({0,st});
    for(int i=1;i<=tot;i++) f[i]=1e18+7;
    for(int i=1;i<=M+n;i++) f[i]=1e18+7;
    f[st]=0;
    while(!q.empty()){
        int u=q.top().second,ww=-q.top().first;q.pop();
        if(ww!=f[u]) continue;
        for(int i=h[u];i;i=e[i].nxt){
            int v=e[i].t,w=e[i].w;
            if(f[v]>f[u]+w) f[v]=f[u]+w,q.push({-f[v],v});
        }
    }
}
void solve(){
    int st,ed;
    cin>>st>>ed;
    dijk(st);
    cout<<f[ed]+t[st]+t[ed]<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C,T;
    cin>>C>>n>>m>>d>>T;
    //m是口的数量.
    for(int i=1;i<=m;i++) cin>>t[i];//口到厅
    for(int i=1;i<=n;i++){//车
        int num;cin>>num;
        tot+=num;
        for(int j=1,x,y;j<=num;j++){
            cin>>x>>y;
            // a[i].push_back(x),b[i].push_back(y);
            add(i+M,x,y),add(x,i+M,y);//向车联系厅。
        }
        //一个是这条路线经过的站台/ 台到厅
        //考虑建边
        //换源最短路。
        //草拟吗。
    }
    while(T--) solve();
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/