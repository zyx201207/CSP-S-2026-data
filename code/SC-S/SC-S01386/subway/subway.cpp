#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define nc() ((p1==p2 && (p2=(p1=buf)+fread(buf, 1, N, stdin))), p1==p2 ? EOF : *p1++)
namespace FIO{
	const int N = 1<<20;
	char buf[N], *p1 = buf, *p2 = buf;
	inline int read(){
		int x = 0, f = 1;
		char c = nc();
		for(;!isdigit(c);c=nc())if(c=='-')f=-1;
		for(;isdigit(c);c=nc())x = x*10+(c^48);
		return f * x;
	}
}
#define rd FIO::read()

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	
	int c = rd, n = rd, m = rd, d = rd, q = rd;
	vector<int>w(m+1, 0);
	for(int i=1;i<=m;i++)w[i] = rd;
	vector<vector<int>>subway(n+1), walk(n+1), g(m+1);
	for(int i = 1;i<=n;i++){
		int k = rd;
		subway[i].reserve(k);
		walk[i].reserve(k);
		for(int i=0;i<k;i++){
			subway[i].push_back(rd);
			g[subway[i].back()].push_back(i);
			walk[i].push_back(rd);
		}
	}
	
	
	while(q--){
		int st = rd, ed = rd;
		
		vector<int>dis(n+1, INT_MAX);
		priority_queue<pair<int, int>>q;
		dis[st] = 0;
		q.push({0, st});
		while(!q.empty()){
			auto x = q.top();
			q.pop();
			int d = x.first, u = x.second;
			d = -d;
			
			for(auto v:g[u]){
				for(int k = 0;k<subway[v].size();k++){
					if(subway[v][k]==u)continue;
					if(dis[subway[v][k]]!=INT_MAX)continue;
					dis[subway[v][k]] = min(dis[subway[v][k]], dis[u]+walk[u]+walk[subway[v][k]]);
					q.push(subway[v][k]);
				}
			}
			
		}
		
		cout << dis[ed] << '\n';
		
	}
	
	
	
	
	
	
	
	
	return 0;
}