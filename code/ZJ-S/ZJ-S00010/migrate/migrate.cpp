#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int C,T,n,d;
struct node{
	int sum,ci;
}dis[maxn];
int vis[maxn];
int a[maxn];
vector<int>e[maxn];
struct edge{
	int x,v;
};
bool operator <(edge a,edge b){
	return a.v>b.v;
}
void bfs(int st){
	priority_queue<edge>que;
	for(int i=1;i<=n;i++){
		vis[i]=dis[i].ci=0;
		dis[i].sum=1e18;
	}
	dis[st].sum=0;
	dis[st].ci=1;
	que.push({st,0});
	while(que.size()){
		int u=que.top().x;
		que.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(dis[v].sum>dis[u].sum+1){
				dis[v].sum=dis[u].sum+1;
				dis[v].ci=dis[u].ci;
				if(!vis[v])que.push({v,dis[v].sum});
			}else if(dis[v].sum==dis[u].sum+1){
				dis[v].ci+=dis[u].ci;
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],e[i].clear();
	for(int i=n;i>=1;i--)a[i]-=a[1];
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>d)break;
			e[j].push_back(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(dis[j].ci==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)solve();
}
