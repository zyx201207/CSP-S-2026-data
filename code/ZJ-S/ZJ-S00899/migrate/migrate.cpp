#include<bits/stdc++.h>
#define ll long long
#define N 2000006
#define endl "\n"
using namespace std;
int c,t;
ll n,d,x[N];
struct P24{
	vector<int>G[N];
	ll dis[5005][5005],ans[5005][5005],vv[5005][5005],res=0;
	queue<int>que;
	int vis[5005];
	void bfs(int s){
		memset(vis,0,sizeof(vis));
		que.push(s);
		while(!que.empty()){
			int u=que.front();
			que.pop();
			vis[u]=1;
			for(int j=0;j<G[u].size();j++){
				int v=G[u][j];
				if(vis[v]){
					if(dis[s][u]+1==dis[s][v])ans[s][v]++;
					continue;
				}else{
					que.push(v);
					dis[s][v]=dis[s][u]+1;
					ans[s][v]=1;
				}
			}
		}
	}
	void main(){
		for(int i=1;i<=n;i++){
			ll r=x[i]+d,l=x[i]-d;
			int pr=upper_bound(x+1,x+n+1,r)-x-1;		
			int pl=lower_bound(x+1,x+n+1,l)-x;
			for(int j=pl;j<=pr;j++){
				if(j==i)continue;
				G[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(ans[i][j]==2)res++;
			}
		}
		cout<<res<<endl;
	}
}p24;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(c<=10)p24.main();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
