#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,T,n,k,ans,dis[100005];
vector<int>v[100005],p;
bool vis[100005];
int fa[100005];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
void check(){
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
        for(auto j:v[i]){
            if(vis[i]&&vis[j])unite(i,j);
        }
    }
    int bl=0;
    for(int i=1;i<=n;i++){
        if(vis[i]&&find(i)==i)bl++;
    }
    if(bl>2)return;
    memset(dis,0x3f,sizeof(dis));
    queue<pair<int,int> >q;
    for(auto i:p){
        dis[i]=0;
        q.push({i,0});
    }
    while(!q.empty()){
        pair<int,int>t=q.front();
        q.pop();
        for(auto i:v[t.first]){
            if(dis[i]<t.second+1){
                dis[i]=t.second+1;
                q.push({i,t.second+1});
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)res=max(res,dis[i]);
    ans=min(ans,res);
}
void choose(int d,int cnt){
    if(d==n+1){
        if(cnt==k)check();
        return ;
    }
    if(cnt<k){
        vis[d]=1;
        p.push_back(d);
        choose(d+1,cnt+1);
        p.pop_back();
        vis[d]=0;
    }
    choose(d+1,cnt);
}
void solve(){
    ans=1e18;
    cin>>n>>k;
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    choose(1,0);
    cout<<ans<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>cc>>T;
    while(T--)solve();
    return 0;
}
