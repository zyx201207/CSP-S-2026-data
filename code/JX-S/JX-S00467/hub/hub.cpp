#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef std::pair<int,int> PII;

#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define lowbit(x) ((x)&-(x))
#define rep(i,l,r) for(auto i(l);i<=(r);++i)
#define per(i,r,l) for(auto i(r);i>=(l);--i)

const int N = 1000010;
const int M = 10000010;
const int INF = 0x3f3f3f3f;

LL read(){
    LL x=0;char ch=getchar(),f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=10*x+(ch^48);ch=getchar();}
    return f?-x:x;
}

int n,k;
int dep[N];
int p[N];

std::vector<int> e[N];
std::vector<int> v;

void dfs1(int u,int fa){
    p[u]=fa;dep[u]=dep[fa]+1;
    for(auto v : e[u]){
        if(v==fa){continue;}
        dfs1(v,u);
    }
}

void dfs2(int u,int fa){
    dep[u]=0;
    for(auto v : e[u]){
        if(v==fa){continue;}
        dfs2(v,u);
        dep[u]=max(dep[u],dep[v]+1);
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c=read(),T=read();

    dep[0]=-1;

    while(T--){
        n=read(),k=read();

        rep(i,1,n){e[i].clear();}
        v.clear();
        rep(i,2,n){
            int u=read(),v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }

        if(k==n){puts("0");continue;}

        dfs1(1,0);
        int x=0;
        rep(i,1,n){if(dep[i]>dep[x]){x=i;}}
        // printf("%d %d\n",x,dep[x]);
        dfs1(x,0);
        int y=x;
        rep(i,1,n){if(dep[i]>dep[x]){x=i;}}
        // printf("%d %d\n",x,dep[x]);
        int z=x;
        while(z){
            if(dep[z]==(dep[x]>>1) || dep[z]==((dep[x]+1)>>1)){v.push_back(z);}
            z=p[z];
        }

        int ans=n;

        for(auto rt : v){
            dfs2(rt,0);

            std::sort(dep+1,dep+1+n,[](int x,int y){return x>y;});

            // rep(i,1,n){printf("%d%c",dep[i]," \n"[i==n]);}

            ans=min(ans,dep[k+1]+1);
        }

        printf("%d\n",ans);
    }

    return 0;
}
/*
wan yuan shen jiu le wo yi min
22:30
*/
