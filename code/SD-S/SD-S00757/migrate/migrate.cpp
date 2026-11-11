#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
using pii = pair<lnt,int>;
/*===================*/
const int N=2e6+10;
int n;
lnt pos[N];
lnt d;
/*===================*/
lnt dist[N];
lnt res[N];
bool vis[N];
void Dijkstra(int s){
	for (int i=1;i<=n;i++){
		dist[i]=4e18+10;
		res[i]=0;
		vis[i]=0;
	}
	priority_queue <int,vector <pii>,greater<pii> > pq;
	dist[s]=0;
	res[s]=1;
	pq.push({0,s});
	while(!pq.empty()){
		pii h=pq.top();
		pq.pop();
		int u=h.second;
		if (vis[u]) continue;
		vis[u]=1; 
		for (int i=u+1;i<=n;i++){
			if (pos[i]-pos[u]>d) break;
			if (dist[i]==dist[u]+1ll){
				res[i]+=res[u];
				pq.push({dist[i],i});
			}else if (dist[i]>dist[u]+1ll){
				res[i]=1;
				dist[i]=dist[u]+1ll;
				pq.push({dist[i],i});
			}
		}
	}
}
/*===================*/
void solve(void){
	cin >> n >> d;
	for (int i=1;i<=n;i++){
		cin >> pos[i];
	}
	lnt ans=0;
	for (int i=1;i<=n;i++){
		Dijkstra(i);
		for (int j=i+1;j<=n;j++){
		//	cout <<i<<" to "<<j<<" "<< res[j] << "\n";
			if (res[j]==2) ans++;
		}
	}
	cout << ans << "\n";
}
/*===================*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c; cin >> c;
	int T = 1; cin >> T;
	while(T--) solve();
	return 0;
}

