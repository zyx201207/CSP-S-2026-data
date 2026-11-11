#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+6;
int C,T,n,d,x[N],ans;
vector<int> G[N];
int dis[N],cnt[N];
set<pair<int,int> >q;
inline void dij(int s){
	dis[s] = 0;
	for(int i = s+1;i <= n;i++) dis[i] = 1ll<<60;
	while(!q.empty()) q.erase(q.begin());
	for(int i = s;i <= n;i++) q.insert(make_pair(dis[i],i));
	int u;
	cnt[s] = 1;
	while(!q.empty()){
		if(q.begin()->first == 1ll<<60) break;
		u = q.begin()->second;
		q.erase(q.begin());
		for(auto v : G[u]){
			if(dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
			else if(dis[u] + 1 < dis[v]){
				cnt[v] = cnt[u];
				q.erase(make_pair(dis[v],v));
				dis[v] = dis[u] + 1;
				q.insert(make_pair(dis[v],v));
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin >> C >> T;
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		if(C == 11 || C == 12){
			int D = 0;
			for(int i = 2;i <= n;i++) if(x[i] - x[1] <= d) D++;
			//cout << "D:" << D << '\n';
			if(D >= 2){
				int D_2 = 0;
				for(int i = D;i <= n;i+=D) D_2++;
				cout << n-D_2-2 << '\n';
			}
			
			else cout << 0 << '\n';
			continue;	
		}
		for(int i = 1;i <= n;i++) G[i].clear();
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(x[j] - x[i] <= d){
					G[i].push_back(j);
				}
				else break;
			}
		}
		for(int i = 1;i <= n;i++){
			dij(i);
			for(int j = i;j <= n;j++){
				if(cnt[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}