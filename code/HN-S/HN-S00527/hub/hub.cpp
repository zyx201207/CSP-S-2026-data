#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1; char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar_unlocked(); }
    while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar_unlocked(); }
    return x*f;
}
const int N=100005;
int c,T,n,k;
int A,B,R,dis[N],mx;
struct edge{
    int to,nxt;
}e[N*2];
int head[N],tot=0;
void add(int u,int v){
    e[++tot]={v,head[u]};
    head[u]=tot;
}
void dfs1(int u,int f){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==f) continue;
        dis[v]=dis[u]+1;
        dfs1(v,u);
    }
}
void dfs2(int u,int f){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==f) continue;
        dis[v]=dis[u]+1;
        dfs2(v,u);
    }
}
void init(){
	memset(head,0,sizeof(head)); tot=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(); T=read();
    while(T--){
		init();
        n=read(); k=read();
        for(int i=1;i<n;i++){
            int u,v; u=read(); v=read();
            add(u,v); add(v,u);
        }
        dfs1(1,0); mx=0;
        for(int i=1;i<=n;i++) if(dis[i]>mx){ mx=dis[i]; A=i; }
        for(int i=1;i<=n;i++) dis[i]=0;
        dfs2(A,0); mx=0;
        for(int i=1;i<=n;i++) if(dis[i]>mx){ mx=dis[i]; B=i; }
        R=mx;
        cout<<R/2-1<<"\n";
    }
    return 0;
}
