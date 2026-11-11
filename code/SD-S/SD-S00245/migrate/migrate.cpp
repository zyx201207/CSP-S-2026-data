#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010];
int vis[2000010],dis[200010],cnt;
vector<int>e[2000010];
void dfs(int x,int v,int d){
	if(x==v&&d==dis[v]){
		cnt++;
		return ;
	}
	for(auto it:e[x]){
		if(!vis[it]){
			vis[it]=1;
			dfs(it,v,d+1);
			vis[it]=0;
		}
	}
}
int zdlj(int u,int v,int n){
	cnt=0;
	for(int i=1;i<=n;i++){
		dis[i]=-1;vis[i]=0;
	}
	queue<int>q;
	q.push(u);
	vis[u]=1;
	dis[u]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto it:e[x]){
			if(!vis[it]){
				vis[it]=1;
				dis[it]=dis[x]+1;
				q.push(it);
			}
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	if(dis[v]==-1)return 0;
	dfs(u,v,0);
	return cnt;
}
void solve(int id){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				e[i].push_back(j);
				e[j].push_back(i);
			}else break;
		}
	}
	int cnt=0;
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			if(zdlj(u,v,n)==2){
//				cerr<<u<<" "<<v<<"\n";
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
	return 0;
}


