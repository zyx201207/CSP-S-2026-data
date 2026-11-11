#include <bits/stdc++.h>
using namespace std;

const int M = 5e5 + 1000;

#define int long long

int c,n,m,d,p;

int w[M];
vector<pair<int,int> > e[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
		
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int u = m + i;
		for(int j = 1;j <= k;j++){
			int x,y;
			cin >> x >> y;
			e[u].push_back({x,y});
			e[x].push_back({u,y});
		} 
	}
	
	while(p--){
		int to1,to2;
		cin >> to1 >> to2;
		priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
		vector<int> f(n+m+1,1e18);
		vector<bool> b(n+m+1,0);
		f[to1] = 0;
		pq.push({0,to1});
		b[to1] = 1;
		while(pq.size()){
			int w = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			if(b[u] == 0)
				continue;
			b[u] = 0;
			for(auto i : e[u])
				if(w + i.second < f[i.first]){
					f[i.first] = w + i.second;
					pq.push({f[i.first],i.first});
					b[i.first] = 1;
				}
		}
		cout << f[to2] + w[to1] + w[to2] << '\n';
	}
	return 0;
}

