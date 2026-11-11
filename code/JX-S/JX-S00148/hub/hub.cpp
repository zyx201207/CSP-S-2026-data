#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=N*2;
int h[N],e[M],ne[M],idx;
vector<int>g;
bitset<N>vs;
int ds[N];
void add(int a,int b){
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
void dfs1(int u,int fa){
    vs[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        if(vs[j]==0&&g[j]==1)dfs1(j,u);
    }
}
void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        ds[j]=ds[u]+1;
        dfs(j,u);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=2e9;
        memset(h,-1,sizeof h);
        idx=0;
        g.clear();
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
        for(int i=1;i<=n;i++){
            if(i<=k)g.push_back(1);
            else g.push_back(0);
        }
        sort(g.begin(),g.end());
        while(next_permutation(g.begin(),g.end())){
            vs.reset();
            int s=0,f=0;
            vector<int>v;
            for(int i=1;i<=n;i++){
                if(g[i])v.push_back(i);
                if(vs[i]==0&&g[i]){
                    dfs1(i,i);
                    s++;
                }
                if(s>2)f=1;
            }
            if(f)continue;
            int res=0;
            for(auto x:v){
                for(auto y:v){
                    if(x==y)continue;
                    memset(ds,0,sizeof ds);
                    dfs(x,x);
                    res=min(res,ds[y]);
                }
            }
            ans=min(ans,res);

        }
        //if(ans=2e9)cout<<1<<"\n";
        cout<<ans+1<<"\n";
    }
    return 0;
}
