#include <bits/stdc++.h>
using namespace std;
const int maxn =1e6+10;
int c,t,n,k;
vector<int> g[maxn];
int a[maxn];
bool vis[maxn];
bool vis2[maxn];
int dis[maxn];
int sum=0x3f3f3f3f;
int ans1,ans;
void dfs3(int x,int y,int step){
    if(x==y){
        sum=min(sum,step);
    }
    for(auto e:g[x]){
        dfs3(e,y,step+1);
    }
}
void dfs2(int u){
    vis2[u]=1;
    for(auto e:g[u]){
        if(vis2[e]==1) continue;
        vis2[e]=1;
        if(vis[e]) dfs2(e);
    }
}
void dfs1(int pos){
    int cnt;
    if(pos==k){
        for(int i=1;i<=n;i++){
            if(vis[i]==1 && vis2[i]==0){
                cnt++;
                dfs2(i);
            }
        }
        if(cnt>2) return;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(vis[i] && vis[j]){
                    sum=0x3f3f3f3f;
                    dfs3(i,j,0);
                    ans1=max(ans1,sum);
                }
            }
        }
        ans=max(ans,ans1);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        a[i]=i;
        vis[i]=0;
        dfs1(pos+1);
        a[i]=0;
        vis[i]=0;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs1(0);
        cout<<ans<<'\n';
    }

    return 0;
}
