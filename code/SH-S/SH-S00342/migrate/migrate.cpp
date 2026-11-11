#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,t;
int n;
ll d;
const int N=2e6+10;
ll a[N];
vector<int> g[N];
int Dist[N];
ll cnt[N];
ll ans=0;
queue<int> q; 
void bfs(int st){
	for(int i=1;i<=n;i++){
		Dist[i]=1e9;
		cnt[i]=0;
	}
	Dist[st]=0,cnt[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(Dist[v]>Dist[u]+1){
				Dist[v]=Dist[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(Dist[v]==Dist[u]+1) cnt[v]+=cnt[u];
		}
	}
	for(int i=st+1;i<=n;i++){
		if(cnt[i]==2) ans++;
	}
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate3.in","r",stdin);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++) bfs(i);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
