#include<bits/stdc++.h>
using namespace std;

constexpr int N=2e6+5;
int c,T,vis[N],flag[N],dis[N],ans,n,k,x,y;
vector<int> e[N];
queue<int> q;

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
    void write(int x){
        if(!x) pc('0');
        while(x) stk[++top]=x%10^48, x/=10;
        while(top) pc(stk[top--]);
        pc('\n');
    }
}io;

void dfs(int u){
    vis[u]=1;
    for(auto v:e[u])
        if(flag[v]&&!vis[v]) dfs(v);
}

int chk(int s){
    if(__builtin_popcount(s)!=k) return 0;
    int cnt=0;
    fill(vis+1,vis+1+n,0);
    for(int i=1;i<=n;i++)
        flag[i]=((s>>i-1)&1);
    for(int i=1;i<=n;i++)
        if(flag[i]&&!vis[i]){
            cnt++;
            if(cnt>2) return 0;
            dfs(i);
        }
    return 1;
}

void bfs(int s){
    int res=0;
    for(int i=1;i<=n;i++)
        if((s>>i-1)&1) q.push(i), dis[i]=0;
        else dis[i]=N;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        res=max(res,dis[u]);
        for(auto v:e[u])
            if(dis[v]==N) dis[v]=dis[u]+1, q.push(v);
    }
    ans=min(ans,res);
}

void sol(){
    io.read(n), io.read(k);
    for(int i=1;i<n;i++)
        io.read(x), io.read(y), e[x].emplace_back(y), e[y].emplace_back(x);
    if(n<=20){
        ans=N;
        for(int i=1;i<(1<<n);i++)
            if(chk(i)) bfs(i);
    }
    io.write(ans);
    for(int i=1;i<=n;i++)
        e[i]={};
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    io.read(c), io.read(T);
    while(T--) sol();
    return 0;
}