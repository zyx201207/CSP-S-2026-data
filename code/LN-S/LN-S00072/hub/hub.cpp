#include<bits/stdc++.h>
#define EQ ==
using namespace std;
typedef long long ll;
const int N=17;
int n,k,ans=1e9;
bool chs[N],vis[N];
vector<int> edge[N];
queue<pair<int,int> > q;
inline void dfs(int t,int f,int num,int kuai,bool cs){
    if(num EQ k){
        if(kuai!=2){
            return ;
        }
        int now=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                vis[j]=0;
            }
            while(!q.empty()){
                q.pop();
            }
            q.push({i,0});vis[i]=1;
            while(!q.empty()){
                int u=q.front(),tag=q.front().second;q.pop();
                if(chs[u]){
                    now=max(now,tag);break;
                }
                for(int v : edge[u]){
                    if(vis[v]){
                        continue;
                    }
                    q.push({v,tag+1});vis[v]=1;
                }
            }
        }
        ans=min(ans,now);
        return ;
    }
    for(int v : edge[t]){
        if(v EQ f){
            continue;
        }
        dfs(v,t,num,kuai,0);
        if(cs){
            dfs(v,t,num+1,kuai,1);
        }
        else if(kuai<2){
            dfs(v,t,num+1,kuai+1,1);
        }
    }
}
inline void solve(){
    cin>>n>>k;ans=1e9;
    for(int t=1;t<=n;t++){
        edge[t].clear();
    }
    for(int t=1;t<n;t++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0,0,0,0);
    chs[1]=1;
    dfs(1,0,1,1,1);
    cout<<ans<<'\n';
}
int main(){
    cin.tie(0)->ios::sync_with_stdio;
    cout.tie(0)->ios::sync_with_stdio;
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}