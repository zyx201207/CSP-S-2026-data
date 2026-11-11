#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>v[210000];
int vis[210000],vv[210000],dis[210000],n,k,ans=2e18,dd[210000];
void dfs2(int x){
	if(vv[x])return ;
	vv[x]=1;
	for(auto it:v[x]){
		if(vis[it])dfs2(it);	
	}
}
void bfs(){
	for(int i=1;i<=n;i++){
		dis[i]=2e18;
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(auto it:v[t]){
			if(dis[it]>=2e9){
				dis[it]=dis[t]+1;
				q.push(it);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dd[i]=min(dd[i],dis[i]);
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		vv[i]=0;
		dd[i]=2e18;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(!vv[i]){
				cnt++;
				dfs2(i);
			}
		}
	}
	if(cnt>2)return ;
	bfs();
	int r=0;
	for(int i=1;i<=n;i++)r=max(r,dd[i]);
//	if(r==1&&ans>r){
//		for(int i=1;i<=n;i++){
//			if(vis[i])cout<<i<<' ';
//		} 
//		cout<<"!!!!!!"<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<dis[i]<<' ';
//		}
//		cout<<endl;
//	}
	ans=min(ans,r);
}
void dfs(int x,int cnt){
	if(x>n){
		if(cnt==k){
			solve2();
		}
		return ;
	}
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
	dfs(x+1,cnt); 
}
void solve(){
	cin>>n>>k;
	ans=2e18;
	for(int i=1;i<=n;i++){
		v[i].clear();
		vis[i]=0;
		vv[i]=0;
		dis[i]=-1;
		dd[i]=2e18;
	}
	for(int i=1;i<n;i++){
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
