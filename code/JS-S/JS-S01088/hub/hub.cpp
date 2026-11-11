#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int popcount(int x){
    int res=0;
    while(x){
        res+=(x&1);
        x>>=1;
    }
    return res;
}
vector<vector<int>> g;
vector<bool> vis;
void dfs(int x,int fa){
    vis[x]=1;
    for(auto v:g[x]) if(v!=fa&&!vis[v]){
        dfs(v,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        int n,k,ans=INT_MAX/2;
        cin>>n>>k;
        vector<vector<int>> e(n+1);
        vector<vector<bool>> co(n+1,vector<bool>(n+1,false));
        vector<bool> in(n+1);
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
            co[u][v]=co[v][u]=1;
        }
        auto check2=[&](){
            g.assign(n+1,vector<int>());
            vis.assign(n+1,false);
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(in[i]&&in[j]&&co[i][j]) 
                        g[i].push_back(j),g[j].push_back(i);
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++) if(in[i]&&!vis[i]){
                cnt++;
                dfs(i,0);
            }
            return cnt==2;
        };
        auto qry=[&](int x){
            queue<pair<int,int>> q;
            q.push({x,0});
            vector<int> vi(n+1,false);
            vi[x]=1;
            while(!q.empty()){
                auto [u,val]=q.front();
                q.pop();
                if(in[u]) return val;
                for(auto v:e[u]) if(!vi[v]){
                    vi[v]=1;
                    q.push({v,val+1});
                }
            }
        };
        for(int mask=1;mask<(1<<n);mask++) if(popcount(mask)==k){
            in.assign(n+1,false);
            for(int i=0;i<n;i++) if(mask&(1<<i)) in[i+1]=true;
            if(!check2()) continue;
            int sum=0;
            for(int i=1;i<=n;i++) sum=max(sum,qry(i));
            ans=min(ans,sum);
        }
        cout<<ans<<'\n';
    }
}