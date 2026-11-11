#include<bits/stdc++.h>
#define pll pair<int,int>
const int N=1e6+10;
using namespace std;
int c,t;
int n,k;
int head[N],nxt[N*2],to[N*2],cnt;
void add(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int fa[N];
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int u){
    if(fa[u]==u) return fa[u];
    return fa[u]=find(fa[u]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    fa[fx]=fy;
}
vector<int> ch;
bool isc[25],vis[25];
int ans=INT_MAX;
queue<pll> q;
void bfs(){
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++){
        vis[i]=0;
        if(isc[i]) {
            q.push(make_pair(i,0));
            vis[i]=1;
        }
    }
    int sum=0;
    while(!q.empty()){
        int dis=q.front().second;
        int id=q.front().first;
        q.pop();
        //cout<<t<<" "<<id<<endl;
        for(int i=head[id];i;i=nxt[i]){
            int v=to[i];
            //if(t==0&&ch[0]==2&&ch[1]==7&&ch[2]==9) cout<<id<<" "<<dis<<" "<<v<<endl;
            if(!vis[v]){
                vis[v]=1;
                //if(t==0&&ch[0]==2&&ch[1]==7&&ch[2]==9) cout<<id<<" "<<dis<<" "<<v<<endl;
                q.push(make_pair(v,dis+1));
                sum=max(sum,dis+1);
            }
        }
    }
    //if(t==0&&ch[0]==2&&ch[1]==7&&ch[2]==9) cout<<sum<<endl;
    ans=min(sum,ans);
}
void dfs(int u){
    if(u>n){
        if(ch.size()!=k) return;
        init();
        for(int i=0;i<ch.size();i++){
            for(int j=head[ch[i]];j;j=nxt[j]){
                if(isc[to[j]]) merge(to[j],i);
            }
            //if(t==2) cout<<ch[i]<<" ";
            //cout<<t<<" "<<ch[i-1]<<" "<<ch[i]<<endl;
        }
        //if(t==2) cout<<endl;
        int lcnt=0;
        for(int i=1;i<=n;i++){
            //if(t==0&&ch[0]==2&&ch[1]==3&&ch[2]==9) cout<<fa[i]<<endl;
            if(isc[i]&&fa[i]==i) lcnt++;
        }
        if(lcnt>2) return;
        bfs();
        //if(t==2) cout<<ans<<endl;
        return;
    }
    if(ch.size()>k) return;
    ch.push_back(u);
    isc[u]=1;
    dfs(u+1);
    ch.pop_back();
    isc[u]=0;
    dfs(u+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        cnt=0;
        for(int i=1;i<=2*n;i++) head[i]=nxt[i]=to[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        if(n<=10){
            ans=INT_MAX;
            ch.clear();
            for(int i=1;i<=n;i++) isc[i]=0;
            dfs(1);
            cout<<ans<<endl;
        }
    }
    return 0;
}