#include<bits/stdc++.h>
using namespace std;
long long dep[1000006],n,k;
bool visd[1000006];
bool vis[1000006],zq[1000006];
vector<long long> g[1000006];
long long bfs(long long s,long long t){
    queue<long long> q,q1;
    q.push(s);
    q1.push(0);
    memset(visd,0,sizeof(visd));
    visd[s] = 1;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        long long w = q1.front();
        q1.pop();
        for(long long v:g[u]){
            if(visd[v]) continue;
            visd[v] = 1;
            q.push(v);
            q1.push(w+1);
            if(v == t){
                return w+1;
            }
        }
    }
    return 0;
}
void tbfs(long long s){
    queue<long long> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        for(long long v:g[u]){
            if(!zq[v]) continue;
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
long long ans;
void dfs(long long x,long long ts,vector<long long> ve,long long cntx){
    if(x>n){
        if(cntx!=k) return;
        memset(vis,0,sizeof(vis));
        memset(zq,0,sizeof(zq));
        long long cnt = 0;
        for(long long v:ve){
            zq[v] = 1;
        }
        for(long long v:ve){
            if(vis[v] == 0){
                tbfs(v);
                cnt++;
            }
        }
        if(cnt<=2) ans = min(ans,ts);
        return;
    }
    dfs(x+1,ts,ve,cntx);
    long long tts = ts;
    for(long long v:ve){
        long long jl = bfs(x,v);
        tts = max(tts,jl);
    }
    ve.push_back(x);
    dfs(x+1,tts,ve,cntx+1);
    ve.pop_back();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(long long i = 1;i<=n;i++) g[i].clear();
        for(long long i = 1;i<n;i++){
            long long l,r;
            cin>>l>>r;
            g[l].push_back(r);
            g[r].push_back(l);
        }
        vector<long long> tmp;
        dfs(1,0,tmp,0);
        cout<<ans<<'\n';
        ans = 1e18;
    }
    return 0;
}
