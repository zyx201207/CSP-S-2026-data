#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2026;
int c,t;
int n,k;
int a[N];
vector<int>l[N];
bool vis[N];
int ans=2e9;

void dfs2(int t){
	vis[t]=1;
	for(int i:l[t])
		if(!vis[i]&&a[i]==1)dfs2(i);
	return;
}
bool check(){
	int cnt=0;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		if(a[i]&&!vis[i])dfs2(i),cnt++;
	}
	return cnt<=2;
}
int bfs(int t){
	memset(vis,0,sizeof vis);
	vis[t]=1;
	queue<int>q1,q2;
	q1.push(t);
	q2.push(0);
	while(q1.size()){
		int x=q1.front(),y=q2.front();
		q1.pop(),q2.pop();
		if(a[x])return y;
		for(int i:l[x]){
			if(vis[i])continue;
			q1.push(i),q2.push(y+1);
			vis[i]=1;
		}
	}
	return -1;
}
void dfs(int t,int cnt){
	if(cnt>k||n-t+1<k-cnt)return;
	if(t>n){
		if(cnt!=k)return;
		if(!check())return;
		int res=0;
		for(int i=1;i<=n;i++){
			if(!a[i])res=max(res,bfs(i));
		}
		ans=min(ans,res);
	}
	a[t]=0;
	dfs(t+1,cnt);
	a[t]=1;
	dfs(t+1,cnt+1);
	return;
}
void solve(){
	ans=2e9;
	cin>>n>>k;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++)l[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		l[u].push_back(v);
		l[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<endl; 
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
