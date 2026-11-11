#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fs first
#define sd second
using namespace std;
const int N=1000005;
vector<int> G[N];
int n,k;
bool v[N];
bool tv[N];
int ans;
void dfs(int x){
    tv[x]=1;
    for(int i=0;i<G[x].size();i++){
        int y=G[x][i];
        if(v[y]&&!tv[y]) dfs(y);
    }
}
bool check(){
    for(int i=1;i<=n;i++) tv[i]=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(v[i]&&!tv[i]) dfs(i),sum++;
    }
    return sum<=2;
}
int dfs2(int x,int fa){
    if(v[x]) return 0;
    int ans=LLONG_MAX/10;
    for(int i=0;i<G[x].size();i++){
        int y=G[x][i];
        if(y==fa) continue;
        ans=min(dfs2(y,x)+1,ans);
    }
    // cout<<ans<<'\n';
    return ans;
}
int getans(){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs2(i,0));
    }
    return ans;
}
void dfs(int dep,int sum){
    if(sum>k||sum+n-dep+1<k) return;
    if(dep>n){
        if(check()) ans=min(ans,getans());
        // if(ans==0){
        //     for(int i=1;i<=n;i++) cout<<v[i];
        //     cout<<'\n';
        // }
        return;
    }
    dfs(dep+1,sum);
    v[dep]=1;
    dfs(dep+1,sum+1);
    v[dep]=0;
}
void work(){
    cin>>n>>k;
    ans=LLONG_MAX;
    for(int i=1;i<=n;i++){
        G[i].clear();
        v[i]=0;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0);
    cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        work();
    }
    return 0;
}