#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 +10;
const int M = 5e5 +10;
const int inf = 1e9 +1e8;
int n,m,d,q;
int w[M];
struct node{
	long long a, ty;
};
vector<node> mp[M];
//long long ans = inf;
int t[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		int pa = 0;
		for(int j = 1;j<=k;j++){
			int a;
			cin>>a;
			cin>>t[i][j];
			mp[a].push_back({pa, i});
			mp[pa].push_back({a, i});
			pa = a;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		ans = inf;
		queue<node> q;
		vector<int> vis(m,0);
		vector<long long> dis(m,0);
		while(q.size()){
			int f = q.front().a;
			int ty = q.front().ty;
			q.pop();
			for(auto k : mp[f]){
				if(vis[k.a]) continue;
				vis[k.a] = 1;
				if(ty == k.ty) dis[k.a] = dis[f];
				else dis[k.a] = dis[f]+t[ty][k.a]+t[k.ty][k.a];
			}
		}
		cout<<dis[y]+2*w[x]+2*w[y]<<'\n';
	}
	return 0;
}
