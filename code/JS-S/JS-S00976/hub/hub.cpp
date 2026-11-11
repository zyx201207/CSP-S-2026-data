#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,x,y,now,cnt,ans,pos;
int cho[1000001],vis[1000001],dis[1000001];
vector<int> e[1000001];
void dfs(int u,int fa){
    vis[u]=1;dis[u]=0;
    for(int i=0;i<e[u].size();i++){
        if(e[u][i]==fa || (!cho[u])){
            continue;
        }
        dfs(e[u][i],u);
    }
}
queue<pair<int,pair<int,int> > > q;
void solve(){
    ans=1e9;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }//cout<<(1<<n)<<endl;
    for(int i=0;i<(1<<n);i++){
        now=1;cnt=0;
        for(int j=1;j<=n;j++){
            if(i&now){
                cnt++;
                cho[j]=1;
            }
            else{
                cho[j]=0;
            }
            now*=2;
        }
        if(cnt!=k){
            continue;
        }
        cnt=0;
        for(int j=1;j<=n;j++){
            vis[j]=0;dis[j]=0;
        }
        for(int j=1;j<=n;j++){
            if(cho[j]&& (!vis[j])){
                cnt++;
                dfs(j,0);
            }
        }
        if(cnt>2){
            continue;
        }
        for(int j=1;j<=n;j++){
            if(cho[j]){
                continue;
            }
            while(!q.empty()){
                q.pop();
            }

            q.push({0,{j,0}});
            while(1){
                now=q.front().second.first;
                cnt=q.front().second.second;
                pos=q.front().first;
                q.pop();
                if(cho[now]){
                    dis[j]=pos;
                    break;
                }
                for(int z=0;z<e[now].size();z++){
                    if(e[now][z]==cnt){
                        continue;
                    }
                    q.push({pos+1,{e[now][z],now}});
                }
            }
        }
        cnt=0;
        for(int j=1;j<=n;j++){
            cnt=max(cnt,dis[j]);
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}

