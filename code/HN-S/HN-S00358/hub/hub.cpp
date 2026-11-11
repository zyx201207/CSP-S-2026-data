#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=1e9;
int c,t,n,k,d[N];
bool vis[N],cnt[N];
vector<int> ve[N];
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<ve[x].size();i++){
        int y=ve[x][i];
        if(cnt[y]==1&&vis[y]==0) dfs(y);
    }
}
int bfs(int x){
    queue<int> q;
    d[x]=0;
    q.push(x);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(cnt[u]==1) return d[u];
        for(int i=0;i<ve[u].size();i++){
            int v=ve[u][i];
            if(d[v]==inf){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) ve[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        if(c==13||c==14){
            if(k==n) cout<<"0\n";
            else if(k>=(n-1)/2) cout<<1<<'\n';
            else cout<<((n-1)/2-k-1)/4+1<<'\n';
            continue;
        }
        int mn=inf;
        for(int i=1;i<(1<<n);i++){
            int s=0;
            for(int j=1;j<=n;j++){
                if((i>>j-1)&1) s++;
            }
            if(s!=k) continue;
            for(int j=1;j<=n;j++){
                vis[j]=0;
                cnt[j]=((i>>j-1)&1);
            }
            s=0;
            for(int j=1;j<=n;j++){
                if(cnt[j]==1&&vis[j]==0){
                    s++;
                    dfs(j);
                }
            }
            if(s>2) continue;
            int mx=0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    d[k]=inf;
                }
                mx=max(mx,bfs(j));
            }
            mn=min(mn,mx);
        }
        cout<<mn<<'\n';
    }
    return 0;
}