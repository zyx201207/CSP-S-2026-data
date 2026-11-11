#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t,n;
long long d,x[N];
vector<int> vc[305];
int dis[305],cnt[305],ans;
priority_queue<pair<int,int> > q;
void dij(int x){
	for(int i=1; i<=n; i++){
		dis[i] = 1e9;
		cnt[i] = 0;
	}
	cnt[x] = 1;
	dis[x] = 0;
	q.push({-dis[x],x});
	while(q.size()){
		int w = -q.top().first,u = q.top().second;
		q.pop();
		if(w>dis[u]) continue;
		for(int i=0; i<vc[u].size(); i++){
			int v = vc[u][i];
			if(dis[v]>dis[u]+1){
				dis[v] = dis[u]+1;
				cnt[v] = cnt[u];
				q.push({-dis[v],v});
			}else if(dis[v]==dis[u]+1){
				cnt[v] += cnt[u];
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(cnt[i]==2) ans++;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c<=6){
		while(t--){
			ans = 0;
			cin >> n >> d;
			//n*(n^2)*log(n^2)多源min_dis计数 
			for(int i=1; i<=n; i++){
				vc[i].clear();
				cin >> x[i];
			}
			for(int i=1; i<=n; i++){
				for(int j=i+1; j<=n; j++){
					if(x[j]-x[i]>d) break;
					vc[i].push_back(j);
					vc[j].push_back(i);
				}
			}
			for(int i=1; i<=n; i++){
				dij(i);
			}
			cout << ans/2 << '\n';
		} 
	}else if(c==11||c==12){
		while(t--){
			cin >> n >> d;
			if(n==1){
				cout << "0\n";
				continue;
			}
			for(int i=1; i<=n; i++){
				cin >> x[i];
			}
			long long cha = x[2]-x[1];
			cha = d/cha;
			if(cha<=1){
				cout << "0\n";
				continue;
			}
			cout << max(0*1ll,n-2*cha+1) << '\n';
		}
	}
	return 0;
} 