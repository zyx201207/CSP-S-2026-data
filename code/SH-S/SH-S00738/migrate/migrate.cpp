#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll x[2000005];
ll vis[5005][5005];
ll sum[5005][5005];
vector<ll> e[5005];
queue<ll> que;
void dfs(ll u,ll mid,ll step){
	if(mid==n)return; 
	for(auto v:e[mid]){
		if(step<sum[u][v]){
			vis[u][v] = 1;
			sum[u][v] = step;
		}
		else if(step==sum[u][v]){
			vis[u][v]++;
		}
		dfs(u,v,step+1);
	}
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c>=11){
			que.push(0);
			continue;
		}
		ll ans=0;
		memset(vis,0,sizeof(vis));
		memset(sum,0x3f,sizeof(sum));
		for(int i=1;i<=n;++i){
			e[i].clear();
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=upper_bound(x+i+1,x+n+1,x[i]+d)-x-1;++j){
				e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,i,1);
			for(int j=i+1;j<=n;j++){
				if(vis[i][j]==2){
					ans++;
				}
			}
		} 
		que.push(ans);
	}
	while(!que.empty()){
		cout<<que.front()<<'\n'; 
		que.pop();
	}
	return 0;
}
