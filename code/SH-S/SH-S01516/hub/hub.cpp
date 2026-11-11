#include<bits/stdc++.h>
using namespace std;

bool bg_M;
template<typename T>
void read(T &a){
    char c;a=0;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
namespace ZZOI{
int C;
int n,K;
const int MAXN=1000'010;
vector<int> GG[MAXN];
int fa[MAXN],siz[MAXN];
int f[1010][1010],g[1010][1010];
int F[1010][1010],G[1010][1010];
void dfs0(int x){
    siz[x]=1;
    for(auto y:GG[x]){
        if(y==fa[x])continue;
        fa[y]=x;
        dfs0(y);
        siz[x]+=siz[y];
    }
}
int dep[MAXN],tfa[MAXN],mx1[MAXN],mx2[MAXN];
void dfs1(int x,int Fa){
    tfa[x]=Fa;
    dep[x]=mx1[x]=mx2[x]=0;
    for(auto y:GG[x])if(y!=Fa){
        dfs1(y,x);
        dep[x]=max(dep[x],dep[y]+1);
        if(dep[y]+1>mx1[x]){
            mx2[x]=mx1[x];
            mx1[x]=dep[y]+1;
        }else if(dep[y]+1>mx2[x])mx2[x]=dep[y]+1;
    }
}
int getf(int X,int Y,int k){
    if(fa[X]==Y){
        return f[X][k];
    }else{
        return g[Y][k];
    }
}
void dfs2(int x,int Fa,int d,int F[1010]){
    for(int i=1;i<=K;++i){
        F[i]=min(F[i],max(getf(x,Fa,i),d));
        // if(x==3)printf("? %d %d : %d %d - %d\n",x,Fa,getf(x,Fa,i),d,f[x][i]);
    }
    for(auto y:GG[x])if(y!=Fa){
        int nd=d;
        if(dep[y]+1==mx1[x])nd=max(nd,mx2[x]);
        else nd=max(nd,mx1[x]);
        // printf("? %d %d %d->%d %d %d %d\n",x,y,d,nd+1,mx1[x],mx2[x],dep[y]);
        dfs2(y,x,nd+1,F);
    }
}
void main(){
    read(n),read(K);
    for(int i=1;i<=n;++i)GG[i].clear();
    for(int i=1,u,v;i<=n-1;++i){
        read(u),read(v);
        GG[u].emplace_back(v);
        GG[v].emplace_back(u);
    }
    dfs0(1);
    auto work1=[&](int X,int Y,int f[1010]){
        dfs1(X,Y);
        priority_queue<pair<int,int>> hp;
        for(int y:GG[X])if(y!=tfa[X])hp.emplace(dep[y],y);
        int now=1;
        while(hp.size()){
            f[now++]=hp.top().first+1;
            int x=hp.top().second;hp.pop();
            for(int y:GG[x])if(y!=tfa[x])hp.emplace(dep[y],y);
        }
        while(now<=K)f[now++]=0;
    };
    auto work2=[&](int X,int Y,int F[1010]){
        dfs1(X,Y);
        for(int i=1;i<=K;++i)F[i]=n;
        dfs2(X,Y,0,F);
    };
    for(int i=2;i<=n;++i){
        work1(i,fa[i],f[i]);
        work1(fa[i],i,g[i]);
    }
    // for(int i=2;i<=n;++i){
    //     printf("f[%d]: ",i);
    //     for(int j=1;j<=K;++j)printf("%d ",f[i][j]);puts("");
    //     printf("g[%d]: ",i);
    //     for(int j=1;j<=K;++j)printf("%d ",g[i][j]);puts("");
    // }
    for(int i=2;i<=n;++i){
        work2(i,fa[i],F[i]);
        work2(fa[i],i,G[i]);
    }
    // for(int i=2;i<=n;++i){
    //     printf("F[%d]: ",i);
    //     for(int j=1;j<=K;++j)printf("%d ",F[i][j]);puts("");
    //     printf("G[%d]: ",i);
    //     for(int j=1;j<=K;++j)printf("%d ",G[i][j]);puts("");
    // }
    int ans=n;
    for(int i=2;i<=n;++i)
        for(int j=1;j<K;++j){
            ans=min(ans,max(F[i][j],G[i][K-j]));
        }
    printf("%d\n",ans);
}
}
bool ed_M;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int T=1;cin>>ZZOI::C>>T;
    while(T--)ZZOI::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&bg_M)/1024.0/1024<<" Mb"<<endl;
    return 0;
}