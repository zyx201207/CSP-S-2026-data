#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,cnt,bel[500002],dist[4002][4002];
vector<int>tu[500002];
bool vis[500002];
int di[500002];
void dfs(int u){
	for(int v:tu[u]){
		if(vis[v]&&!bel[v]){
			bel[v]=bel[u];
			dfs(v);
		}
	}
}
queue<int>q;
void solve(){
	cnt=0;
	for(int i=1;i<=n;i++){
		bel[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]&&!bel[i]){
			if(cnt>=2)return;
			bel[i]=++cnt;
			dfs(i);
		}
	}
//	cout<<"vis=1:";
	for(int i=1;i<=n;i++){
		if(vis[i]){
//			cout<<i<<" ";
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		for(int j=1;j<=n;j++)di[j]=-1;
		while(q.size())q.pop();
		di[i]=0;
		q.push(i);
		int x=0;
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int v:tu[u]){
				if(vis[v]){
					x=di[u]+1;
					break;
				}
				if(di[v]==-1){
					di[v]=di[u]+1;
					q.push(v);
				}
			}
			if(x)break;
		}
		res=max(res,x);
//		cout<<"the "<<i<<" mn:"<<x<<endl;
	}
	ans=min(ans,res);
}
void dfs(int p,int a){
	if(p>n){
		if(a==k)solve();
		return;
	}
	dfs(p+1,a);
	if(a<k){
		vis[p]=1;
		dfs(p+1,a+1);
		vis[p]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)tu[i].clear();
		ans=1e9;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			tu[u].push_back(v);
			tu[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
