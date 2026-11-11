#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int M=5e5+5,N=505;
constexpr ll INF=1e17;
int c,n,m,d,q,w[M],k,len[M];
ll dis[N][N];
struct Node{
    int p,w;
}vet[M][21];

struct IO{
    static constexpr size_t V=1<<20;
    char ibuf[V],obuf[V],stk[30];
    size_t pi,po,len,top;

    void flush(){
        cout.write(obuf,po), po=0;
    }
    ~IO(){
        flush();
    }
    char gc(){
        if(pi==len) cin.read(ibuf,V), len=cin.gcount(), pi=0;
        return len?ibuf[pi++]:0;
    }
    void pc(char ch){
        if(po==V) flush();
        obuf[po++]=ch;
    }

    void read(int& x){
        char ch=gc();
        x=0;
        while(ch<'0'||ch>'9') ch=gc();
        while(ch>='0'&&ch<='9') x=x*10+(ch^48), ch=gc();
    }
    void write(ll x){
        if(!x) pc('0');
        while(x) stk[++top]=x%10^48, x/=10;
        while(top) pc(stk[top--]);
        pc('\n');
    }
}io;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    io.read(c), io.read(n), io.read(m), io.read(d), io.read(q);
    for(int i=1;i<=m;i++)
        io.read(w[i]);
    for(int i=1;i<=n;i++){
        int k,a,t;
        io.read(k);
        fill(dis[i]+1,dis[i]+1+n,INF);
        dis[i][i]=0;
        for(int j=1;j<=k;j++){
            io.read(a), io.read(t);
            vet[a][++len[a]]={i,t};
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<len[i];j++)
            for(int k=j+1;k<=len[i];k++){
                int x=vet[i][j].p, y=vet[i][k].p;
                ll z=vet[i][j].w+vet[i][k].w;
                dis[x][y]=dis[y][x]=min(dis[x][y],z);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    for(int o=1;o<=q;o++){
        int x,y;
        ll ans=INF;
        io.read(x), io.read(y);
        for(int i=1;i<=len[x];i++){
            int p=vet[x][i].p, w=vet[x][i].w;
            for(int j=1;j<=len[y];j++)
                ans=min(ans,dis[p][vet[y][j].p]+w+vet[y][j].w);
        }
        ans+=w[x]+w[y];
        io.write(ans);
    }
    return 0;
}