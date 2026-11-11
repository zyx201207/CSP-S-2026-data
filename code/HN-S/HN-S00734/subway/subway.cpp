#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005];
struct edge{int to,val;};
vector<edge>graph[500505];
int read(){
    int res=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
    while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}
inline int spfa(int st,int ed){
    queue<int>q;q.push(st);int dis[500505];
    memset(dis,0x3f,sizeof(dis));dis[st]=0;
    while(q.size()){
        int u=q.front();q.pop();
        for(int i=0;i<graph[u].size();++i){
            int v=graph[u][i].to,w=graph[u][i].val;
            if(dis[v]>dis[u]+w){dis[v]=dis[u]+w;q.push(v);}
        }
    }
    return dis[ed];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;++i)w[i]=read();
    for(int i=1;i<=n;++i){
        int k=read();
        for(int j=1;j<=k;++j){
            int a=read(),t=read();
            graph[m+i].push_back((edge){a,t});
            graph[a].push_back((edge){m+i,t});
        }
    }
    for(int i=1;i<=q;++i){
        int u=read(),v=read();
        printf("%lld\n",w[u]+w[v]+spfa(u,v));
    }
}
//g++ -o subway subway.cpp -std=c++14 -O2 -static