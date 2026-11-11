#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
T read(){
    T x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
    }
    return x*f;
}
struct pii{
    int w,v;
    bool operator <(const pii &b)const{
        return w>b.w;
    }
};

const int M=5e5+10;
int w[M],vis[M*2+1];
int c,n,m,d,q,x,in[M*2+1];
vector<pii> g[M*2+1];
bool cmp(pii X,pii Y){
    return in[X.v]>in[Y.v];
}
int dij(int u,int v){
    x++;
    int fa;
    if(g[v].size()==1){
        fa=g[v][0].v;
    }
    priority_queue<pii> pq;
    pq.push({0,u});
    while(!pq.empty()){
        pii T=pq.top();
        pq.pop();
        // cerr<<T.v<<" "<<T.w<<"\n";
        if(vis[T.v]==x) continue;
        vis[T.v]=x;
        // cerr<<T.v<<" "<<T.w<<"\n";
        if(T.v==v) return T.w;
        // cerr<<T.v<<" "<<T.w<<"\n";
        for(auto X:g[T.v]){
            if(vis[X.v]==x) continue;
            if(g[X.v].size()==1&&T.v!=fa) break;
            pq.push({T.w+X.w,X.v});
            // cerr<<T.v<<" "<<X.v<<"\n";
        }
    }
    return 0;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read<int>();
    n=read<int>();
    m=read<int>();
    d=read<int>();
    q=read<int>();
    for(int i=1;i<=m;i++) w[i]=read<int>();
    for(int i=1;i<=n;i++){
        int K;
        cin>>K;
        for(int j=1;j<=K;j++){
            int ss,tt;
            cin>>ss>>tt;
            g[ss].push_back({tt,i+m});
            in[ss]++;
            g[i+m].push_back({tt,ss});
            in[i+m]++;
        }
    }
    for(int i=1;i<=n+m;i++){
        sort(g[i].begin(),g[i].end(),cmp);
    }
    // for(int i=1;i<=n+m;i++){
    //     cout<<i<<" ";
    //     if(g[i].size()>=1){
    //         for(auto xx:g[i]){
    //             cout<<xx.v<<" ";
    //         }
    //         cout<<"\n";
    //     }
        
    // }
    while(q--){
        int u,v;
        u=read<int>(),v=read<int>();
        printf("%d\n",dij(u,v)+w[u]+w[v]);
    }
}