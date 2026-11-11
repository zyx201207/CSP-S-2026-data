/*
宇宙冷漠，这张牌我是，非常了解的。
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    if(f) x=-x;
}
int n,m;
const int N=1e6;
vector<int> gph[N+5];
bool deld[N+5],fa[N+5];
void dfs(int u){
    for(int v:gph[u]){
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs(v);
    }
}
int head,tail,que[N+5],dis[N+5];
void solve(){
    read(n);read(m);
    for(int i=1;i<=n;++i){
        gph[i].clear();
    }
    for(int i=1,u,v;i<n;++i){
        read(u);read(v);
        gph[u].emplace_back(v);
        gph[v].emplace_back(u);
    }
    if(n==2){
        putchar('0');
        putchar('\n');
        return;
    }
    dfs(1);
    for(int i=0;i<(1<<n);++i){
        if(__builtin_popcount(i)!=m) continue;
        int num=0;
        for(int j=1;j<=n;++j){
            if((i>>j)&1) deld[j]=1,dis[j]=0;
            else deld[j]=0,dis[j]=INF;
        }
        for(int j=2;j<=n;++j){
            if(deld[fa[j]]&&deld[j]) ++num;
        }
        if(num!=m-2) continue;
        head=0,tail=-1;
        for(int j=1;j<=n;++j) if(deld[j]) que[++tail]=j;
    }
    write(0);
    cout<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int Type,Tcases=1;
    read(Type);
    read(Tcases);
    while(Tcases--) solve();
    return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6
在古代，穷人一拳打倒十个保安到底有多爽。
*/