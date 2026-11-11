#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct val{int ln,u,sum;};
struct vp:vector<val>{
    void init(){
        (this->back()).sum=0;
        for(int i=size()-1;~i;i--){
            (*this)[i].sum+=(*this)[i].ln;
            if(i)(*this)[i-1].sum+=(*this)[i].sum;
        }
    }
    int qry(int v){
        int l=0,r=size(),mid;
        while(l<r){
            mid=(l+r)>>1;
            if((*this)[mid].ln>v)r=mid;
            else l=mid+1;
        }
        if(l==size())return 0;
        return (*this)[l].sum-(size()-l)*v;
    }
};
const int N=5e5+500;
mt19937 rad((0xC3+0xC5)>>1);
int c,T,n,k,cut[N];
struct node{int v,i;};
vector<node>g[N];
int mdp[N],fa[N],fi[N],dep[N],lson[N];
void dfs(int u,int ff,int ffi){
    // cerr<<"dfs: "<<u<<'\n';
    fa[u]=ff,fi[u]=ffi,mdp[u]=1,dep[u]=1,lson[u]=0;
    for(auto[v,i]:g[u])if(!cut[i]&&v!=ff){
        // cerr<<"dfs: "<<v<<" -> "<<u<<'\n';
        dfs(v,u,i);
        mdp[u]=max(mdp[u],mdp[v]+1);
        if(mdp[v]>mdp[lson[u]])lson[u]=v;
    }
}
vp des(int u){
    dfs(u,0,0);int rt=u;
    while(lson[rt])rt=lson[rt];
    dfs(rt,0,0);int ln=mdp[rt];
    while(lson[rt])rt=lson[rt];
    while(2*mdp[rt]<ln+1)rt=fa[rt];
    dfs(rt,0,0);
    queue<int>q;q.push(rt);
    vp ans;
    while(q.size()){
        int v=q.front();q.pop();
        // cerr<<"bfs: "<<v<<' '<<lson[v]<<"\n";
        int tt=v;while(lson[tt])tt=lson[tt];
        ans.push_back({mdp[v],tt,0});
        for(auto[s,i]:g[v])if(!cut[i]&&s!=fa[v]&&s!=lson[v])
            q.push(s);
    }reverse(ans.begin(),ans.end());
    return ans;
}
void work(){
    cin>>n>>k;
    for(int i=0;i<n+5;i++)g[i].clear();
    memset(cut,0,(n+5)*sizeof(int));
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    dfs(1,0,0);int rt=1;
    while(lson[rt])rt=lson[rt];
    dfs(rt,0,0);int ln=mdp[rt];
    while(lson[rt])rt=lson[rt];
    while(2*mdp[rt]<ln+1)rt=fa[rt];
    cut[fi[lson[rt]]]=1;
    // cerr<<fi[lson[rt]]<<"\n";
    int a=rt,b=lson[rt];
    // cerr<<a<<' '<<b<<"\n";
    vp sa=des(a),sb=des(b);
    sa.init(),sb.init();
    // for(auto[ln,id,sum]:sa)cerr<<ln<<','<<id<<','<<sum<<" ";
    // cerr<<"\n";
    // for(auto[ln,id,sum]:sb)cerr<<ln<<','<<id<<','<<sum<<" ";
    // cerr<<"\n";
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        // cerr<<mid<<' '<<sa.qry(mid)+sb.qry(mid)<<'\n';
        if(sa.qry(mid)+sb.qry(mid)<=k)r=mid;
        else l=mid+1;
    }cout<<mid+1<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(cin>>c>>T;T--;)work();
    cout.flush();
    return 0;
}