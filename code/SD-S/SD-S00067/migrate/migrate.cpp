#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int c,t,n,d,x[2000010],mi,sum,ans;
vector<int> g[2000010];
int vis[2000010];
struct O_o{
	int x,s;
};
queue<O_o> q;
int bfs(int start,int end){
	q.push({start,0});
	for(int i=1;i<=n;++i){
		vis[i]=0;
	}
	while(!q.empty()){
		int u=q.front().x;
		int st=q.front().s;
		q.pop();
		if(u==end){
			return st;
		}
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push({v,st+abs(x[v]-x[u])});
		}
	}
}
void dfs(int a,int st,int end){
	if(sum>2) return;
	if(st>mi) return;
	if(a==end){
		if(st==mi){
			sum++;
		}
		return;
	}
	for(int i=0;i<g[a].size();++i){
		int t=g[a][i];
		if(vis[t]) continue;
		vis[t]=1;
		dfs(t,st+abs(x[t]-x[a]),end);
//		vis[t]=0;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		} 
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j) continue;
				mi=bfs(i,j);
//				cout<<mi<<" "<<i<<" "<<j<<"\n";
				for(int i=1;i<=n;++i){
					vis[i]=0;
				}
				sum=0;
				dfs(i,0,j);
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
