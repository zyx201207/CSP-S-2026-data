#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+1;
long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void write(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct edge{long long v,w;};
struct node{
    int x,sum;
};
long long C,n,m,d,q;
long long w[maxn];
bool vis[maxn];
vector<edge> G[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    C=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;++i) w[i]=read();
    for(int i=1;i<=n;++i){
        int k=read(),u=read(),tf=read(),v=read(),ts=read();
        G[u].push_back({v,tf+ts});
        G[v].push_back({u,tf+ts});
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        long long x=read(),y=read();
        queue<node> q;
        q.push({x,0});
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            vis[u.x]=1;
            if(u.x==y){
                write(u.sum+w[x]+w[y]);
                putchar('\n');
                break;
            }
            for(auto e:G[u.x]){
                long long v=e.v,w=e.w;
                if(vis[v]) continue;
                q.push({v,u.sum+w});
            }
        }
    }
    return 0;
}
