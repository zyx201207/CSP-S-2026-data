#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

const int N=4010;

int c,T;
int n,k;
int to[N<<1],ne[N<<1],h[N],idx;
int nt;
int f[N][N];
int U[N],V[N];
int ff[N];
int hh[N];

void add(int a,int b){
    to[++idx]=b,ne[idx]=h[a],h[a]=idx;
}
int mx,rt;
void findfar(int u,int fa=0,int dep=0){
    ff[u]=fa;
    if(dep>mx) mx=dep,rt=u;
    for(int i=h[u];i;i=ne[i]){
        int v=to[i];
        if((i>>1)==nt||v==fa) continue;
        findfar(v,u,dep+1);
    }
}
void dfs(int u,int fa=0){
    for(int i=0;i<=n;++i) f[u][i]=1;
    hh[u]=0;
    for(int i=h[u];i;i=ne[i]){
        int v=to[i];
        if((i>>1)==nt||v==fa) continue;
        dfs(v,u);
        hh[u]=max(hh[u],hh[v]);
        for(int j=0;j<=n;++j)
            f[u][j]+=f[v][j];
    }++hh[u];
    for(int i=hh[u];i<=n;++i) f[u][i]=0;
    // for(int i=0;i<=n;++i) printf("- %d %d %d\n",u,i,f[u][i]);
}
void work(){

    scanf("%d%d",&n,&k);
    idx=1;
    for(int i=1;i<=n;++i) h[i]=0;
    for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),add(u,v),add(v,u),U[i]=u,V[i]=v;
    int res=n;
    U[0]=1;
    for(int i=0;i<n;++i){
        nt=i;
        int a=U[i],b=V[i];
        mx=-1;
        findfar(a);
        int da=rt;
        mx=-1;
        findfar(da);
        int db=rt;
        static int path[N];
        int cnt=0,p=db;
        while(p!=da) path[++cnt]=p,p=ff[p];
        path[++cnt]=da;
        int mid=path[(cnt+1)/2],mid2=0;
        dfs(mid);
        if(b){
            mx=-1;
            findfar(b);
            da=rt;
            mx=-1;
            findfar(da);
            db=rt;
            static int path[N];
            cnt=0,p=db;
            while(p!=da) path[++cnt]=p,p=ff[p];
            path[++cnt]=da;
            mid2=path[(cnt+1)/2];
            dfs(mid2);
        }
        for(int mn=0;mn<=n;++mn) if(f[mid][mn]+(mid2?f[mid2][mn]:0)<=k){
            res=min(mn,res);
            // printf("asdfasdf %d %d\n",i,mn);
            break;
        }
    }
    printf("%d\n",res);
}
int main(){
    Fre("hub");

    scanf("%d%d",&c,&T);
    while(T--){
        work();
    }

    return 0;
}