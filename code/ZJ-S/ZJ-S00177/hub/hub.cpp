#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;
int c,t,n,k,vis[1000005],ans,mn,vvis[1000005],dis[1000005];
vector<int>s[1000005];
void dfs(int x,int fa,int len){
    if(vis[x]) mn=min(mn,len);
    // cout<<x<<' '<<len<<'\n';
    for(int i=0;i<s[x].size();i++){
        int y=s[x][i];
        if(y==fa) continue;
        dfs(y,x,len+1);
    }
}
void dfs3(int x,int fa,int len){
    // if(vis[x]) mn=min(mn,len);
    dis[x]=min(dis[x],len);
    // cout<<x<<' '<<len<<'\n';
    for(int i=0;i<s[x].size();i++){
        int y=s[x][i];
        if(y==fa) continue;
        dfs3(y,x,len+1);
    }
}
void dfs2(int x,int fa,int len){
    // if(vis[x]) mn=min(mn,len);
    // cout<<x<<' '<<len<<'\n';
    vvis[x]=1;
    for(int i=0;i<s[x].size();i++){
        int y=s[x][i];
        if(y==fa||!vis[y]) continue;
        dfs2(y,x,len+1);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;ans=1e18;
        for(int i=1;i<=n;i++) s[i].clear();
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            s[x].push_back(y);
            s[y].push_back(x);
        }
        if(k<=2&&n>20){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    for(int l=1;l<=n;l++) vis[l]=0,vvis[l]=0,dis[l]=1e18;
                    vis[i]=1,vis[j]=1;dis[i]=0,dis[j]=0;
                    int mx=0;
                    dfs3(i,0,0);dfs3(j,0,0);
                    for(int l=1;l<=n;l++) mx=max(mx,dis[l]);
                    ans=min(ans,mx);
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        for(int s=0;s<(1<<n);s++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))) cnt++,vis[i]=1;
                else vis[i]=0;
                vvis[i]=0;
            }
            if(cnt!=k) continue;
            int res=0;
            for(int i=1;i<=n;i++){
                if(vis[i]&&!vvis[i]) dfs2(i,0,0),res++;
            }
            if(res>2) continue;
            int mx=0;
            for(int i=1;i<=n;i++){
                if(vis[i]) continue;
                mn=1e18;
                dfs(i,0,0);
                mx=max(mx,mn);
            }
            ans=min(ans,mx);
        }
        cout<<ans<<'\n';
    }
    return 0;
}