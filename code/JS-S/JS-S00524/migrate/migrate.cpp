#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e6+10;
const int inf=1e9;

struct node{
	ll k,idx;
};

int c,t,n;
ll d;
ll a[maxn];
vector<int> g[maxn];
ll dis[maxn],cnt[maxn];
queue<int> q;

void bfs(int s){
	for(int i=1;i<=n;i++){
		dis[i]=inf;cnt[i]=0;
	}
	q.push(s);
	dis[s]=0;cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int k=dis[u];
		for(int v:g[u]){
			if(k+1<=dis[v] && dis[v]==inf){
				dis[v]=k+1;
				cnt[v]+=cnt[u];
				q.push(v);
			}else if(k+1<=dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					g[j].push_back(i);
				}
			}
		}
		
		// for(int i=1;i<=n;i++){
		// 	cout<<i<<": ";
		// 	for(int v:g[i]){
		// 		cout<<v<<' ';
		// 	}
		// 	cout<<'\n';
		// }

		ll ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i;j<=n;j++){
				// cout<<dis[j]<<' '<<cnt[j]<<'\n';
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';

	}

	return 0;
}