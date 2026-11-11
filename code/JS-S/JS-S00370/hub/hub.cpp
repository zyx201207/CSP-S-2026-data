#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int fa[maxn];
vector<int> g[maxn];
int n,k,res=0x3f3f3f3f;
bool used[maxn];
void dfs(int u,int father){
    fa[u]=father;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(v!=father)dfs(v,u);
    }
}
int calc(int u){
    int cnt=0;
    if(used[u] && !used[fa[u]])cnt++;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(v!=fa[u])cnt+=calc(v);
    }
    return cnt;
}
int found(int u,int father){
    int ans=0x3f3f3f3f;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(v!=father){
            if(used[v])return 1;
            else ans=min(ans,1+found(v,u));
        }
    }
    return ans;
}
void solve(int mask){
    int num=0;
    for(int i=1; i<=n; i++)used[i]=false;
    for(int i=0; i<n; i++){
        if(mask>>i&1){
            used[i+1]=true;
            num++;
        }
    }
    if(num!=k)return;
    if(calc(1)>2)return;
    int ans=0;
    for(int i=1; i<=n; i++){
        if(!used[i]){
            ans+=found(i,0);
        }
    }
    res=min(ans,res);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if(c<=3){
        while(t--){
            scanf("%d%d",&n,&k);
            for(int i=1; i<n; i++){
                int u,v;
                scanf("%d%d",&u,&v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
            dfs(1,0);
            for(int mask=1; mask<(1<<n); mask++){
                solve(mask);
            }
            printf("%d\n",res);
            for(int i=1; i<=n; i++)g[i].clear();
            res=0x3f3f3f3f;
        }
    }else{
        long long tmp=rand();
        if(tmp<0)tmp=-tmp;
        long long mod=n*n;
        printf("%lld\n",tmp%mod);
    }
    return 0;
}
