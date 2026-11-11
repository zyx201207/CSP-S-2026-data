#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,k;
    scanf("%lld%lld",&n,&k);
    vector<vector<int>>G(n+2,vector<int>(0));
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int>dep(n+2,0);
    vector<vector<int>>fa(n+2,vector<int>(31,0));
    function<void(int,int)>init=[&](int u,int f){
        dep[u]=dep[f]+1;
        fa[u][0]=f;
        for(auto v:G[u])if(v!=f){
            init(v,u);
        }
    };init(1,0);
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
    function<int(int,int)>lca=[&](int x,int y){
        if(x==y)return x;
        if(dep[x]<dep[y])swap(x,y);
        for(int j=20;j>=0;j--)if(dep[fa[x][j]]>=dep[y]){
            x=fa[x][j];
        }
        if(x==y)return x;
        for(int j=20;j>=0;j--)if(fa[x][j]!=fa[y][j]){
            x=fa[x][j];
            y=fa[y][j];
        }
        return fa[x][0];
    };
    int ans=1e18;
    for(int mask=0;mask<(1<<n);mask++){
        int cnt=0;
        vector<int>dot;
        for(int i=1;i<=n;i++){
            if((mask&(1<<(i-1)))!=0){
                cnt++;
                dot.push_back(i);
            }
        }
        sort(dot.begin(),dot.end());
        if(cnt!=k)continue;
        vector<bool>vis(n+2,0);
        function<void(int)>bfs=[&](int s){
            vis[s]=true;
            queue<int>q;
            q.push(s);
            while(!q.empty()){
                auto u=q.front();q.pop();
                for(auto v:G[u])if(!vis[v]){
                    bool lll=true;
                    for(auto d:dot)if(d==v)lll=false;
                    if(lll)continue;
                    vis[v]=true;
                    q.push(v);
                }
            }
        };
        int tmp=0;
        for(auto d:dot)if(!vis[d]){
            tmp++;
            bfs(d);
        }
        if(tmp>2)continue;

        vector<int>dist(n+2,1e18);
        int mx=0;
        for(auto d:dot){
            for(int j=1;j<=n;j++){
                int l=lca(j,d);
                // if(mask==262){
                //     cout<<"lll"<<" "<<d<<" "<<j<<" "<<l<<" "<<dep[d]+dep[j]-2*dep[l]<<endl;
                // }
                dist[j]=min(dist[j],dep[d]+dep[j]-2*dep[l]);
            }
        }
        for(int i=1;i<=n;i++)mx=max(mx,dist[i]);
        // if(mx<ans){
            // cout<<":"<<mask<<" "<<mx<<" "<<dist[10]<<endl;
        // }
        ans=min(ans,mx);
    }
    printf("%lld\n",ans);

    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,_;
    scanf("%lld%lld",&c,&_);
    while(_--)solve();
    return 0;
}