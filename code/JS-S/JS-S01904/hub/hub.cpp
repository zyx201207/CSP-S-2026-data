#include<bits/stdc++.h>
using namespace std;
int _,t,n,k,dis[12][12];
vector<int>mp[1000005];
bool b(int i){
    int cnt=0;
    while(i){
        cnt+=i%2;i/=2;
    }
    return cnt==k;
}
void f(int s){
    queue<int>q;
    bool vis[12]={};
    q.push(s),vis[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int y:mp[x]){
            if(!vis[y]){
                dis[s][y]=dis[s][x]+1;vis[y]=1;
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i)mp[i].clear();
        memset(dis,0,sizeof(dis));
        int ans=0x3f3f3f3f;
        for(int i=1;i<n;++i){
            int u,v;cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(int i=1;i<=n;++i)f(i);
        for(int i=(1<<k)-1;i<=(1<<n);++i){
            int p=0;
            if(!b(i))continue;
            for(int j=1;j<=n;++j){
                if((1<<(j-1))&i)continue;
                for(int l=1;l<=n;++l){
                    if((1<<(j-1))&i==0)continue;
                    p=max(p,dis[j][l]);
                }
            }
            ans=min(ans,p);
        }
        cout<<ans<<endl;
    }
    return 0;
}