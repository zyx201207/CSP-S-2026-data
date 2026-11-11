#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using pii = pair<int,int>;
const int M = 5e5 + 505;
vector<pii> g[M];
int zj[M];
int f[M];
int h[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	long long ans = 0;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		int t;
		cin>>t;
		zj[i] = t;
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int a,t;
			cin>>a>>t;
			g[a].emplace_back(m + i,t);
			g[m + i].emplace_back(a,t);
		}
	}
	for(int j = 0;j <= m + n;j++){
		h[j] = INT_MAX;
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin>>x>>y;
		ans += zj[x] + zj[y];
		queue<int> q;
		q.push(x);
		f[x] = 1;
		h[x] = 0;
		while(!q.empty()){
			int t = q.front();
			q.pop();
			for(auto res : g[t]){
				int u = res.first,w = res.second;
				if(f[u] == 0){
					f[u] = 1;
					q.push(u);
				}
				h[u] = min(h[t] + w,h[u]);
				h[t] = min(h[u] + w,h[t]);
			}
		}
		cout<<h[y] + ans<<endl;
		ans = 0;
		for(int j = 0;j <= m + n;j++){
			f[j] = 0;
			h[j] = INT_MAX;
		}
	}
	return 0;
}