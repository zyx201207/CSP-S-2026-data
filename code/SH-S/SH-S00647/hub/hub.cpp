#include<bits/stdc++.h>
//Things will always be better, just let time plays
using namespace std;
#define HACKILLER_FAST ios::sync_with_stdio(false),cin.tie(0)
//#define int long long
#define ull unsigned long long
#define vc vector
#define pii pair<int,int>
#define pb push_back
#define ls x<<1
#define rs x<<1|1
struct node{
    int val,id;
    friend bool operator < (const node&x,const node&y) {
        return x.val < y.val;
    }
};
struct dat{
    int xi,step;
};
int id,T,n,k,p[25],a[1000005],d[1000005],fa[1000005],vis[1000005],st[22][1000005],ans = 1e9,plan[25],vst[1000005],nw;
vc<int> es[1000005];
priority_queue<node> pq;

inline void dfs(int u,int pr){
    st[0][u] = pr;
    for(int i = 1;i <= 20;++i) st[i][u] = st[i-1][st[i-1][u]];
    d[u] = d[pr]+1;
    for(int v:es[u]){
        if(v == pr) continue;
        dfs(v,u);
    }
}
inline int lca(int x,int y){
    if(d[x] > d[y]) swap(x,y);
    for(int i = 20;i >= 0;--i){
        if(d[st[i][y]] >= d[x]) y = st[i][y];
    }
    for(int i = 20;i >= 0;--i){
        if(st[i][x] != st[i][y]) x = st[i][x],y = st[i][y];
    }
    return x == y ? x : st[0][x];
}
inline int dis(int x,int y){
    return d[x]+d[y]-2*d[lca(x,y)];
}
inline int fd(int x){
    if(fa[x] == x) return x;
    return fa[x] = fd(fa[x]);
}
inline bool ok(){
    for(int i = 1;i <= n;++i) fa[i] = i;
    for(int i = 1;i <= n;++i){
        if(plan[i]){
            for(int j:es[i]){
                if(plan[j]) fa[fd(i)] = fd(j);
            }
        }
    }
    int pos1 = -1,pos2 = -1;
    for(int i = 1;i <= n;++i){
        if(plan[i]){
            int fu = fd(i);
            if(fu == pos1 || fu == pos2) continue;
            if(pos1 == -1) pos1 = fu;
            else if(pos2 == -1) pos2 = fu;
            else return false;
        }
    }
    return true;
}
inline void bf(int step,int num){
    if(num == k){
        if(ok()){
            int res = 0;
            for(int i = 1;i <= n;++i){
                if(!plan[i]){
                    int mn = 1e9;
                    for(int j = 1;j <= n;++j){
                        if(plan[j]) mn = min(mn,dis(i,j));
                    }
                    res = max(res,mn);
                }
            }
            ans = min(ans,res);
        }
        return ;
    }
    if(step > n) return ;
    plan[step] = 1;
    bf(step+1,num+1);
    plan[step] = 0;
    bf(step+1,num);
}
inline int query(int x,int y){
    //cerr<<"QUERY: "<<x<<' '<<y<<'\n';
    y = min(y,d[x]-1);
    for(int i = 20;i >= 0;--i){
        if(p[i] <= y){
            y-=p[i];
            x = st[i][x];
            //cerr<<x<<' '<<y<<'\n';
        }
    }
    return x;
}
inline void bfs(int x,int y){
    //cerr<<"BFS " <<x<<' '<<y<<'\n';
    queue<dat> q;
    q.push({x,0});
    vis[x] = 1;
    vst[x] = ++nw;
    while(!q.empty()){
        int u = q.front().xi,step = q.front().step;
        vis[u] = 1;
        q.pop();
        if(step == y) continue;
        for(int v:es[u]){
            if(vst[v] == nw) continue;
            vis[v] = 1,vst[v] = nw;
            //cerr<<v<<'\n';
            q.push({v,step+1});
        }
    }
    //cerr<<"------"<<'\n';
}
inline bool chk(int mid){
    //cerr<<"CHKING"<<' '<<mid<<'\n';
    for(int i = 1;i <= n;++i) vis[i] = 0;
    for(int i = 1;i <= n;++i) pq.push({d[i],i});
    int res = 0;
    while(!pq.empty()){
        int x = pq.top().id;
        pq.pop();
        if(vis[x]) continue;
        int y = query(x,mid);
        //cerr<<x<<' '<<y<<'\n';
        //if(vis[y]) continue;
        //cerr<<x<<' '<<y<<'\n';
        bfs(y,mid);
        ++res;
    }
    //cerr<<res<<'\n';
    //for(int i = 1;i <= n;++i){
    //    if(!vis[i]) return false;
    //}
    if(res > k) return false;
    return true;
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    HACKILLER_FAST;
    p[0] = 1;
    for(int i = 1;i <= 20;++i) p[i] = p[i-1]*2;
    cin>>id>>T;
    while(T--){
        for(int i = 1;i <= n;++i) es[i].clear();
        cin>>n>>k;
        for(int i = 1,u,v;i < n;++i){
            cin>>u>>v;
            es[u].pb(v),es[v].pb(u);
        }
        dfs(1,0);
        if(id <= 3){
            ans = 1e9;
            bf(1,0);
            cout<<ans<<'\n';
            continue;
        }
        int l = 0,r = n;
        while(l <= r){
            int mid = l+r>>1;
            if(chk(mid)) ans = mid,r = mid-1;
            else l = mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//ForEverLOVE
/*
I give credit to the last 2 hours when I get do my best in problem 3 and problem 4
I hope I can go to WC
My score is about 100+100+56+30 = 286
Wish that no accidents occurs

Words are difficult to express emotions
For Ever LOVE
TO
ANGELA JIANG~ 
*/
