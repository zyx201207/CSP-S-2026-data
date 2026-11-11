#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int n,k;
int dis[N];
vector<int> e[N];
int fa[N],idx;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int u){
    for(int v:e[u]){
        if(dis[v]!=-1)continue;
        dis[v]=dis[u]+1;
        dfs(v);
    }
}
int check(vector<int> v){
    if(v.size()!=k)return 0x3f3f3f3f;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool f1=0;
            for(int k=0;k<e[i].size();k++)if(e[i][k]==j){f1=1;break;}
            if(f1){
                int p=find(i),q=find(j);
                if(p!=q)fa[p]=q;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(fa[v[i]]==v[i])cnt++;
    }
    if(cnt>2)return 0x3f3f3f3f;
    int res=0;
    for(int i=1;i<=n;i++){
        int minn=0x3f3f3f3f;
        memset(dis,-1,sizeof dis);
        dis[i]=0;
        dfs(i);
        for(int j=0;j<v.size();j++){
            minn=min(minn,dis[v[j]]);
        }
        res=max(res,minn);
    }
    return res;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<(1<<n);i++){
        vector<int> s;
        for(int j=0;j<n;j++){
           if((i>>j)&1)s.push_back(j+1);
        }
        ans=min(ans,check(s));
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
