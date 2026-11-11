#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int inf = 1e6+10;
int c,t,n,k,u,v,s[N],vis[N],d[N],used[N],ans;
vector<int>e[N];
void dfs(int x){
	used[x]=1;
	for(auto it:e[x]){
		if(s[it]&&!used[it])dfs(it);
	}
}
void calc(int x){
	if(x==k){
		queue<int>q;
		for(int i=1;i<=n;++i){
			vis[i]=0,used[i]=0;
			if(s[i]){
				q.push(i);
				d[i]=0;
			}else{
				d[i]=inf;
			}
		}
		int ok=0;
		for(int i=1;i<=n;++i){
			if(!used[i]&&s[i]){
				dfs(i);
				++ok;
			}
		}
		if(ok>2)return;
		while(!q.empty()){
			int now=q.front();q.pop();
			vis[now]=1;
			for(auto it:e[now]){
				if(!vis[it]){
					d[it]=min(d[now]+1,d[it]);
					q.push(it);
				}
			}
		}
		int mx=0;
		for(int i=1;i<=n;++i)mx=max(mx,d[i]);
		ans=min(ans,mx);
		return;
	}
	for(int i=1;i<=n;++i){
		if(!s[i]){
			s[i]=1;
			calc(x+1);
			s[i]=0;
		}
	}
}
void solve(){
	cin>>n>>k;
	ans=inf;
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1;i<n;++i){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	calc(0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}


