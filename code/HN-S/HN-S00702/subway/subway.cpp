#include <bits/stdc++.h>
using namespace std;
int w[500005];
int t[500005];
struct st{
	int a;
	int t;
};
vector<int> sta[500005];
vector< vector< st > > ways;
vector<int> res;
int vis[500005];
queue<int> que;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m;i++){
		cin>>w[i];
	}
	for(int i = 0, k; i<n; i++){
		cin>>k;
		vector< st > way;
		for(int j = 0, a, t; j < k; j++){
			cin>>a>>t;
			way.push_back({a,t});
			sta[a].push_back(i); 
		}
		ways.push_back(way); 
		
	}
	for(int i = 0, x, y; i < q; i++){
		cin>>x>>y;
		int r = w[x]+w[y];
		que.push(x);
		while(!que.empty()){
			int idx = que.front();
			que.pop();
			if (idx == y){
				r+=t[idx];
				break;
			}
			for(int j = 1; j < sta[idx].size();j++){
				vector< st > way = ways[sta[idx][j]];
				for(int jj = 1; jj < way.size();jj++){
					if(vis[way[jj].a])continue;
					vis[idx] = true;
					que.push(way[jj].a);
					t[way[jj].a] = t[idx]+way[idx].t+way[jj].t;
				}
			}
			
		}
		res.push_back(r);
	}
	for(int i = 0; i<res.size(); i++){
		cout<<res[i]<<'\n';
	}
	return 0;
} 
