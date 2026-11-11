#include<bits/stdc++.h>
#define int long long 
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int n,k;
vector<int>g[1010];
int dep[1010],mx[1010],fa[1010];
void dfs1(int u,int f,int ban){
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(auto v:g[u])if(v!=ban&&v!=f){
        dfs1(v,u,ban);
    }
}
int dfss=0;
void dfs2(int u,int f,int ban){
    fa[u]=f;
    mx[u]=1;
    for(auto v:g[u])if(v!=ban&&v!=f){
        dfs2(v,u,ban);
        mx[u]=max(mx[v]+1,mx[u]);
    }
}
int tot=0;
int cut(int u,int v,int d){
    for(int i=1;i<=n;i++)dep[i]=0;
    dep[u]=1;
    dfs1(u,0,v);
    int tmp=1;
    for(int i=2;i<=n;i++)if(dep[i]>dep[tmp])tmp=i;
    for(int i=1;i<=n;i++)dep[i]=0;
    for(int i=1;i<=n;i++)fa[i]=0;
    dep[tmp]=1;
    dfs1(tmp,0,v);
    for(int i=1;i<=n;i++)if(dep[i]>dep[tmp])tmp=i;
    vector<int>vec;
    vec.reserve(n);
    vec.push_back(tmp);
    while(fa[tmp])vec.push_back(tmp=fa[tmp]);
    int rt=vec[vec.size()/2];
    for(int i=1;i<=n;i++)fa[i]=mx[i]=0;
    dfs2(rt,v,v);
    vector<vector<int>>cnt(mx[rt]+1);
    cnt[mx[rt]].push_back(rt);
    int ans=0;
    for(int i=mx[rt];i>d;i--){
        for(int j=0;j<cnt[i].size();j++){
            int x=cnt[i][j];
            ans++;
            for(auto y:g[x])if(y!=fa[x]&&y!=v){
                cnt[mx[y]].push_back(y);
            }
        }
    }
    return max(1ll,ans);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=n+1;
    for(int u=1;u<=n;u++){
        for(auto v:g[u]){
            int l=0,r=n+1;
            while(l<r){
                int mid=l+r>>1;
                if(cut(u,v,mid)+cut(v,u,mid)<=k)r=mid;
                else l=mid+1;
            }
            ans=min(ans,l);
        }
        int l=0,r=n+1;
        while(l<r){
            int mid=l+r>>1;
            if(cut(u,-1,mid)<=k)r=mid;
            else l=mid+1;
        }
        ans=min(ans,l);
    }
    cout<<ans<<endl;
}
signed main(){
    file("hub");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
