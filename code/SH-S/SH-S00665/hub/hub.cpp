#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,cnt,ans,v[N],st[N];
bool vis[N],sp[N];
vector<int> e[N];
queue<pair<int,int> > q;
void dfs(int x){
	st[x]=cnt;
	for(auto y:e[x])
	  if(!st[y]&&vis[y]) dfs(y);
	return ;
}
int bfs(int x){
	while(!q.empty()) q.pop();
	q.push({x,0}),sp[x]=true;
	while(!q.empty()){
	  int u=q.front().first,cur=q.front().second;
	  sp[u]=true; q.pop();
	  if(vis[u]) return cur;
	  for(auto v:e[u])
	    if(!sp[v]) q.push({v,cur+1});
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
	  cin>>n>>k; ans=N;
	  for(int i=1;i<N;i++) e[i].clear();
	  for(int i=1;i<n;i++){
	    int u,v; cin>>u>>v;
	    e[u].push_back(v),e[v].push_back(u);
	  }
	  int MX=N;
	  if(n<=30) MX=(1<<n);
	  for(int i=1;i<MX;i++){
	    int tot=0,res=0; cnt=0;
	    for(int j=1;j<=n;j++){
	      st[j]=0,vis[j]=false;
	      if(i&(1<<(j-1))) vis[j]=true,v[++tot]=j;
	    }
	    if(tot!=k) continue;
	    sort(v+1,v+k+1);
	    for(int j=1;j<=n;j++){
	      if(!vis[j]||st[j]) continue;
	      cnt++; dfs(j);
	    }
	    if(cnt>2) continue;
	    for(int j=1;j<=n;j++){
	      if(vis[j]) continue;
	      for(int p=1;p<=n;p++) sp[p]=false;
	      res=max(res,bfs(j));
	    }
	    ans=min(ans,res);
	  }
	  cout<<ans<<endl;
	}
	return 0;
}