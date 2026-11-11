#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

// #define debug(...) fprintf(stderr,__VA_ARGS__)
// #define debug(...) void()

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> G(n);
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v,u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dfn(n),rdfn(n);
    int cdfn=0;
    vector<int> dep(n),maxd(n),outd(n),fa(n);
    auto dfs1=[&](auto&&dfs,int u)->void {
        // debug("dfs1: u = %d\n",u);
        dfn[u]=cdfn++;
        for(int v:G[u])if(v!=fa[u]){
            fa[v]=u,dep[v]=dep[u]+1;
            dfs(dfs,v);
            maxd[u]=max(maxd[u],maxd[v]+1);
        }
        rdfn[u]=cdfn;
    };
    dfs1(dfs1,0);
    auto dfs2=[&](auto&&dfs,int u)->void {
        // debug("dfs2: u = %d\n",u);
        int max1=-1,max2=-1;
        for(int v:G[u])if(v!=fa[u]){
            if(maxd[v]>max1)max2=max1,max1=maxd[v];
            else max2=max(max2,maxd[v]);
        }
        for(int v:G[u])if(v!=fa[u]){
            outd[v]=max(outd[u],maxd[v]==max1?max2:max1)+1;
            dfs(dfs,v);
        }
    };
    outd[0]=-1;
    dfs2(dfs2,0);
    auto qmaxd=[&](int u,int from)->int {
        return fa[u]==from?maxd[u]:outd[from];
    };
    vector<int> f(n),g(n);
    auto check=[&](const int lim)->bool {
        auto dfs1=[&](auto&&dfs,int u)->void {
            // debug("dfs1: u = %d\n",u);
            f[u]=1;
            for(int v:G[u])if(v!=fa[u])dfs(dfs,v),f[u]+=f[v];
            if(maxd[u]<lim)f[u]=0;
        };
        dfs1(dfs1,0);
        auto dfs2=[&](auto&&dfs,int u)->void {
            // debug("dfs2: u = %d\n",u);
            int sum=0;
            for(int v:G[u])if(v!=fa[u])sum+=f[v];
            for(int v:G[u])if(v!=fa[u]){
                g[v]=outd[v]<lim?0:g[u]+sum-f[v]+1;
                dfs(dfs,v);
            }
        };
        g[0]=0;
        dfs2(dfs2,0);
        auto qf=[&](int u,int from)->int {
            return max(1,fa[u]==from?f[u]:g[from]);
        };
        vector<int> pth(n);
        int success=0,base;
        multiset<int> L,R;
        auto dfs3=[&](auto&&dfs,int u,int from,int ptr)->void {
            // debug("dfs3: u = %d, from = %d\n",u,from);
            int maxn=0;
            if(!L.empty())maxn=max(maxn,*L.rbegin()+1);
            if(!R.empty())maxn=max(maxn,*R.rbegin()+ptr);
            // int maxn2=0;
            // for(int i=0;i<ptr;i++)maxn2=max(maxn2,min(i+1,ptr-i)+pth[i]);
            // if(maxn!=maxn2){
            //     debug("ptr = %d, maxn = %d, maxn2 = %d\n",ptr,maxn,maxn2);
            // }
            // assert(maxn==maxn2);
            // debug("u = %d, maxn = %d\n",u,maxn);
            if(maxn>lim)return;
            int max1=-1,max2=-1;
            for(int v:G[u])if(v!=from){
                const int x=qmaxd(v,u);
                if(x>max1)max2=max1,max1=x;
                else max2=max(max2,x);
            }
            if(qf(u,from)+base<=k){
                // debug("success! u = %d, %d + %d\n",u,qf(u,from),base);
                success=1;
                return;
            }
            for(int v:G[u])if(v!=from){
                pth[ptr]=(qmaxd(v,u)==max1?max2:max1)+1;
                R.insert(pth[ptr]-ptr);
                if(ptr&1)R.erase(R.find(pth[ptr>>1]-(ptr>>1))),L.insert(pth[ptr>>1]+(ptr>>1));
                // debug("push %d\n",pth.back());
                dfs(dfs,v,u,ptr+1);
                if(success)return;
                if(ptr&1)R.insert(pth[ptr>>1]-(ptr>>1)),L.erase(L.find(pth[ptr>>1]+(ptr>>1)));
                R.erase(R.find(pth[ptr]-ptr));
            }
        };
        for(int x=0;x<n;x++)for(int y:G[x]){
            // debug("edge %d %d\n",x,y);
            L.clear(),R.clear();
            base=qf(x,y);
            dfs3(dfs3,y,x,0);
            if(success)return 1;
        }
        return 0;
    };
    // cout<<check(1)<<endl;
    // return;
    int L=0,R=n;
    while(L<R){
        int mid=(L+R)>>1;
        // debug("check %d %d %d\n",L,R,mid);
        if(check(mid))R=mid;
        else L=mid+1;
    }
    cout<<L<<endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _,T;
    cin>>_>>T;
    while(T--)solve();
    return 0;
}