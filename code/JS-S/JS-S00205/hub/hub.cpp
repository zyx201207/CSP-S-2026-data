// #define DEBUG
#include<bits/stdc++.h>
using namespace std;
ifstream fin("hub.in");
ofstream fout("hub.out");
#ifdef DEBUG
#define fin cin
#define fout cout
#endif
using i64=long long;
using f64=double;
using pii=pair<int,int>;
using vci=vector<int,int>;
#define pbk push_back
#define ctn continue
#define rtn return
#define brk break
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pre(i,a,b) for(int i=(a);i>=(b);--i)
#define re(i,a) for(int i=1;i<=(a);++i)
#define rel(i,a) for(int i=0;i<(a);++i)
#define chmn(a,b) a=min((a),(b))
#define chmx(a,b) a=max((a),(b))
/*--------------------------------------------------------*/
vector<int>tr[15];
bool vis[15];
void dfs1(int u){
    vis[u]=1;
    for(auto v:tr[u])if(!vis[v])dfs1(v);
}pii dfs2(int u,int dis,int fa){
    int ret1=0,ret2=(vis[u]?0:1e9);
    for(auto v:tr[u])if(v!=fa){
        auto p=dfs2(v,(vis[v]?0:dis+1),u);
        chmx(ret1,p.first);chmn(ret2,p.second+1);
    }rtn {max(ret1,min(dis,ret2)),ret2};
}
void solve(){
    int n,k;fin>>n>>k;
    rel(i,n)tr[i].clear();
    re(i,n-1){
        int u,v;fin>>u>>v;
        tr[u-1].pbk(v-1);tr[v-1].pbk(u-1);
    }int ans=1000;
    rel(mask,1<<n){
        int cnt=__builtin_popcount(mask);
        if(cnt!=k)ctn;
        rel(i,n)vis[i]=!(mask&(1<<i));
        cnt=0;
        rel(i,n)if(!vis[i])dfs1(i),cnt++;
        if(cnt>2)ctn;
        rel(i,n)vis[i]=(mask&(1<<i));
        chmn(ans,
             dfs2(0,(vis[0]?0:1000),-1).first
             );
    }fout<<ans<<"\n";
}
int main(){
    int zhangyimo_daishuya,T;fin>>zhangyimo_daishuya>>T;
    while(T--)solve();
}
