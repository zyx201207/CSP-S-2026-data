#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,f[N][21],fa[N],ans;
int d[N];
vector<int>g[N];
vector<int>v;
void dfs1(int x,int fa,int dep){
    d[x]=dep;
    for(auto y:g[x]){
        if(y==fa){
            continue;
        }
        f[y][0]=x;
        for(int i=1;f[f[y][i-1]][i-1]!=-1;i++){
            f[y][i]=f[f[y][i-1]][i-1];
        }
        dfs1(y,x,dep+1);
    }
}
int lca(int x,int y){
    if(d[x]<d[y]){
        swap(x,y);
    }
    for(int i=20;i>=0;i--){
        int tx=f[x][i];
        if(tx!=-1&&d[tx]>=d[y]){
            x=tx;
        }
    }
    if(x==y){
        return x;
    }
    for(int i=20;i>=0;i--){
        int tx=f[x][i],ty=f[y][i];
        if(tx!=-1&&ty!=-1&&tx!=ty){
            x=tx,y=ty;
        }
    }
    return f[x][0];
}
int dis(int x,int y){
    return d[x]+d[y]-(d[lca(x,y)]<<1);
}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void uni(int x,int y){
    fa[Find(y)]=Find(x);
}
void dfs(int now,int cho){
    if(now==n+1){
        if(cho==m){
            for(int i=1;i<=n;i++){
                fa[i]=i;
            }
            for(int i=1;i<v.size();i++){
                uni(v[i-1],v[i]);
            }
            set<int>s;
            for(auto x:v){
                s.insert(Find(x));
            }
            if(s.size()==2){
                int res=INT_MAX;
                for(int i=1;i<=n;i++){
                    int cnt=INT_MAX;
                    for(auto x:v){
                        cnt=min(cnt,dis(i,x));
                    }
                    res=max(res,cnt);
                }
                ans=min(ans,res);
            }
        }
        return;
    }
    for(int i=now;i<=n-m+1+cho;i++){
        v.push_back(i);
        dfs(now+1,cho+1);
        v.erase(v.end()-1);
    }
}
void solve(){
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(f,-1,sizeof(f));
    ans=INT_MAX;
    dfs1(1,-1,1);
    dfs(1,0);
    cout<<ans<<"\n";
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t>>t;
    while(t--){
        solve();
    }
    return 0;
}
