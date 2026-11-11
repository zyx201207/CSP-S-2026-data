#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int c,n,k,cnt,ans,a[N];
vector<int>H[N];
bool vis[N],p[N],vvis[N];
void init(){
	for(int i=1;i<=n;i++) H[i].clear();
	cnt=0;
	ans=1e9;
}
bool ck(){
	for(int i=1;i<=n;i++) vis[i]=0;
	int ind=0;
	for(int i=1;i<=k;i++){
		if(!vis[a[i]]) ind++;
		if(ind>2) return 0;
		for(const auto& v:H[a[i]]) vis[v]=ind;
	}
//	cout<<ind<<' ';
	return 1;
}
int bfs(int x){
	queue<pair<int,int> >q;
	q.push({x,0});
	for(int i=1;i<=n;i++) vvis[i]=0;
	while(!q.empty()){
		int u=q.front().first,w=q.front().second;
//		cout<<u<<' ';
		q.pop();
		if(p[u]) return w;
		vvis[u]=1;
		for(const auto& i:H[u]){
			if(vvis[i]) continue;
			q.push({i,w+1});
		}
	}
	return 1e9;
}
int get(){
	int ans=0;
	for(int i=1;i<=n;i++) p[i]=0;
	for(int i=1;i<=k;i++) p[a[i]]=1;
	for(int i=1;i<=n;i++){
		ans=max(ans,bfs(i));
//		cout<<'\n';
	}
	return ans;
}
void dfs(int x,int y){
	if(x>k){
		if(!ck()) return;
		ans=min(ans,get());
//		cout<<'\n';
//		if(ans==1){
//			for(int i=1;i<=k;i++) cout<<a[i]<<" \n"[i==k];
//		}
		return;
	}
	if(y>n) return;
	a[x]=y;
	dfs(x+1,y+1);
	dfs(x,y+1);
}
void solve(){
	init();
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		H[u].push_back(v);
		H[v].push_back(u);
	}
	for(int i=1;i<n;i++)
		if(H[i].size()==1) cnt++;
	dfs(1,1);
	cout<<ans<<'\n';
	return;
}
int main(){
//	freopen("hub4.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>c>>T;
//	T=1;
	for(;T;T--) solve();
	return 0;
}
