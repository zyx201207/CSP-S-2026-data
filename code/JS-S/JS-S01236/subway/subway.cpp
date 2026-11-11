#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
typedef pair<int,int> pii;
inline int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x*f;
}
inline void write(ll x){
    if(x<0){
        putchar_unlocked('-');
        x=-x;
    }else if(x>=10){
        write(x/10);
    }
    putchar_unlocked(x%10+'0');
}
const int N=507,M=5e5+7;
int c,n,m,d,q;
map<pii,int>t;
map<pii,bool>vis;
map<pii,ll>dist;
int w[M],k[N];
vector<int>g[M];
vector<int>sta[M];
struct node{
    int x,type;
    bool operator<(const node other)const{
        return dist[{type,x}]>dist[{other.type,other.x}];
    }
};
ll getdist(pii x){
    ll res=dist[x];
    return !res?0x3f3f3f3f3f3f3f3f:res;
}
inline void dijkstra(int s,int e){
    priority_queue<node>q;
    for(auto type:sta[s]){
        dist[{type,s}]=w[s]+t[{type,s}];
        q.push(node{s,type});
    }
    while(!q.empty()){
        int x=q.top().x,type=q.top().type;
        q.pop();
        if(vis[{type,x}]){
            continue;
        }
        vis[{type,x}]=true;
        for(auto y:sta[x]){
            if(y==type||vis[{y,x}]){
                continue;
            }
            ll newdist=dist[{type,x}]+t[{type,x}]+t[{y,x}];
            if(getdist({y,x})>newdist){
                dist[{y,x}]=newdist;
                q.push(node{x,y});
            }
        }
        for(auto y:g[type]){
            if(y==x||vis[{type,y}]){
                continue;
            }
            if(dist[{type,x}]<getdist({type,y})){
                dist[{type,y}]=dist[{type,x}];
                q.push(node{y,type});
            }
        }
    }
    ll ans=LLONG_MAX;
    for(auto type:sta[e]){
        ans=min(ans,getdist({type,e})+t[{type,e}]+w[e]);
    }
    write(ans),putchar_unlocked('\n');
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int siz=read();
        for(int j=1;j<=siz;j++){
            int x=read();
            t[{i,x}]=read();
            sta[x].push_back(i);
            g[i].push_back(x);
        }
    }
    while(q--){
        int x=read(),y=read();
        dist.clear();
        vis.clear();
        dijkstra(x,y);
    }
    return 0;
}
