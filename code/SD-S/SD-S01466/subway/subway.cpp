#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c, n, m, d, q;
struct edge{
	int to, w;
};
vector<edge>g[1000010];
queue<int>qu;
int gnd[1000010], s[1000010], t[1000010];
bool vis[1000010];
int f[1000010];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i ++){
		cin>>gnd[i];
	}
	for(int i = 1; i <= n; i ++){
		int k;
		cin>>k;
		//cout<<111<<endl;
		for(int j = 1; j <= k; j ++){
			cin>>s[j]>>t[j];
		}
		for(int j1 = 1; j1 <= k; j1 ++){
			int j = s[j1];
			//g[j].push_back({j, 0});
			for(int d1 = j1+1; d1 <= k; d1 ++){
				int d = s[d1];
				bool f1 = 1, f2 = 2;
				/* 
				for(int e1 = 0; e1 < g[j].size(); e1 ++){//cout<<111;
					if(g[j][e1].to == d){
						g[j][e1].w = min(g[j][e1].w, t[j1] + t[d1]);
						//cout<<g[j][e1].w<<endl;
						//cout<<111;
						f1 = 0;
					}
				}
				for(int e1 = 0; e1 < g[d].size(); e1 ++){
					if(g[d][e1].to == j){
						g[d][e1].w = min(g[d][e1].w, t[j1] + t[d1]);
						//cout<<g[d][e1].w<<endl;
						f2 = 0;
					}
				}*/
				if(f1)g[j].push_back({d, t[j1] + t[d1]});
				if(f2)g[d].push_back({j, t[j1] + t[d1]});
				//cout<<j<<' '<<g[j].to<<' '<<g[j].w<<endl;;
			}
		}
	}
	//cout<<111;
	//for(int i = 1; i <= m; i ++){
	//	//cout<<g[i].size();
	//	for(auto j:g[i]){//cout<<111;
	//		cout<<i<<' '<<j.to<<' '<<j.w<<endl;
	//	}
	//}
	
	while(q--){
		int x, y;
		cin>>x>>y;
		memset(vis, 0, sizeof vis);
		memset(f, 0x3f,sizeof f);
		int ans = 0;
		while(!qu.empty()) qu.pop();
		qu.push(x);
		f[x] = 0;
		vis[x] = 1;
		while(!qu.empty()){
			int t = qu.front();
			qu.pop();
			//vis[t] = 0;
			for(auto i:g[t]){
//				if(!vis[i.to]){
//					cout<<t<<' '<<i.to<<endl;
					int pre1 = f[i.to];
					f[i.to] = min(f[i.to], f[t] + i.w);
					if(f[i.to] != pre1) qu.push(i.to);
					
					vis[i.to] = 1;
//				}
			}
		}
		cout<<f[y] + gnd[x] + gnd[y]<<'\n';
	}
	return 0;
}
