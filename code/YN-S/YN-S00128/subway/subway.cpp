#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;
#define min(a,b) (a<b)?a:a=b;
int c,n,m,ddd,q,w[500010],k[510],x,y,tmp;bool fh;
vector<pair<int,int>>v[510],vd[500010];
long long e[510][510],res;char cc;
int read(){
    tmp=fh=0;cc=getchar_unlocked();
    while(cc<48||cc>57)fh=(cc=='-'),cc=getchar_unlocked();
    while(cc>=48&&cc<=57)tmp=(tmp<<3)+(tmp<<1)+(cc^48),cc=getchar_unlocked();
    return(fh)?-tmp:tmp;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>ddd>>q;
    for(int i=1;i<=m;++i)w[i]=read();
    for(int i=1;i<=n;++i){
        k[i]=read();
        for(int j=1;j<=k[i];++j)x=read(),y=read(),v[i].push_back({x,y}),vd[x].push_back({i,y});
        for(int j=1;j<=n;++j)e[i][j]=0x3f3f3f3f3f3f3f3f;
    }for(int i=1;i<=n;++i){
        for(pair<int,int> j:v[i])
            for(pair<int,int> k:vd[j.first])
                if(k.first!=i)min(e[i][k.first],(long long)j.second+k.second);
    }for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            if(e[i][k]!=0x3f3f3f3f3f3f3f3f)
                for(int j=1;j<=n;++j)
                    min(e[i][j],e[i][k]+e[k][j]);
    for(int i=1;i<=n;++i)e[i][i]=0;
    while(q--){
        x=read(),y=read();
        res=0x3f3f3f3f3f3f3f3f;
        for(pair<int,int> i:vd[x])
            for(pair<int,int> j:vd[y])
                min(res,e[i.first][j.first]+i.second+j.second);
        printf("%lld\n",res+w[x]+w[y]);
    }return 0;
}
