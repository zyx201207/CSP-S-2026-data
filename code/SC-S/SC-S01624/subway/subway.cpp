#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 5;
int id,n,m,d,q;
int w[N],k[1005];
struct node{
	int v,line,tv;
};
vector<node>edge[N];
vector<int>t[N];
vector<int>lxy[N];
int top[N],dist[N],dp[505][505];
map<pair<int,int>,int>mp;
void dij(int u,int kkk){
	fill(dist + 1,dist + m + 1,1e18);
	dist[u] = 0;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
	q.push(make_pair(0,make_pair(u,kkk)));
	while(!q.empty()){
		auto tp = q.top();
		int u = tp.second.first,w = tp.first,line = tp.second.second;
//		cout << u << " " << w <<" " << line << endl; 
		q.pop();
		if(dist[u] < w) continue;
		dp[kkk][line] = min(dp[kkk][line],w);
		for(auto i : edge[u]){
			int cost = w;
			if(i.line != line){
				cost = cost + mp[make_pair(u,line)] + mp[make_pair(u,i.line)];
			}
			dp[kkk][i.line] = min(dp[kkk][i.line],cost);
			if(dist[i.v] > cost){
				dist[i.v] = cost;
				q.push(make_pair(cost,make_pair(i.v,i.line)));
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	memset(dp,0x3f,sizeof dp);
	cin >> id >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		int u,v = 0;
		for(int j = 1;j <= k[i];j++){
			u = v;
			cin >> v;
			int p;
			cin >> p;
			t[i].push_back(p);
			mp[make_pair(v,i)] = p;
			lxy[v].push_back(i);
			if(u){
				edge[u].push_back((node){v,i,t[i][j - 1]});
				edge[v].push_back((node){u,i,t[i][j - 2]});
//				cout << "s:" << endl;
//				cout << u << " " << v << " " <<i << " " << t[i][j - 2] << " " << t[i][j - 1] << endl;
			}
			top[i] = v;
		}
	}
	if(n == 2){
		int minn = 1e18;
		for(int i = 1;i <= m;i++){
			if(lxy[i].size() == 2){
				minn = min(minn,mp[make_pair(i,1)] + mp[make_pair(i,2)]);
			}
		}
		while(q--){
			int l,r;
			cin >> l >> r;
			int ans = 1e18;
			for(auto i : lxy[l]){
				for(auto j : lxy[r]){
					if(i == j)
						ans = min(ans,w[l] + w[r] + mp[make_pair(l,i)] + mp[make_pair(r,j)]);
					else
						ans = min(ans,minn + w[l] + w[r] + mp[make_pair(l,i)] + mp[make_pair(r,j)]);
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
//	for(int i = 1;i <= m;i++){
//		cout << i<<endl;
//		for(auto j : edge[i]){
//			cout << j.v << " " << j.line << " " << j.tu << " " << j.tv << endl;
//		}
//	}
	for(int i = 1;i <= n;i++){
		dij(top[i],i);
	}
//	dij(1,1);
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	while(q--){
		int l,r;
		cin >> l >> r;
		int ans = 1e18;
		for(auto i : lxy[l]){
			for(auto j : lxy[r]){
				ans = min(ans,dp[i][j] + w[l] + w[r] + mp[make_pair(l,i)] + mp[make_pair(r,j)]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//本地6、7大样例 9s+能不能放点分过去ccf？ 16:39 