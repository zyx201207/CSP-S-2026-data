#include<bits/stdc++.h>
using namespace std;
int w[500009],h[509][509];
struct Edge{
	int v,w;
};
vector<Edge> d[1009];
bool vst[500009];
int dis[500009];
void dfsA(int u){
	for(int i = 0;i < d[u].size();i++){
		int v = d[u][i].v;
		if(vst[v]) continue;
		vst[v] = 1;
		if(dis[v] == 0) dis[v] = dis[u] + d[u][i].w;
		dis[v] = min(dis[v],dis[u] + d[u][i].w);
		dfsA(v);
		vst[v] = 0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,D,q;
	cin>>c>>n>>m>>D>>q;
	bool A = 1,B = 1;
	int T = 0;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	vector<int> a[m],t[m];
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		if(k != 2) A = 0;
		if(k == 2){
			int a1,a2,t1,t2;
			cin>>a1>>t1>>a2>>t2;
			d[a1].push_back({a2,t1 + t2});
			d[a2].push_back({a1,t1 + t2});
			//d[a1][a2] = d[a2][a1] = t1 + t2;
			a[a1].push_back(i);
			t[a1].push_back(t1);
			a[a2].push_back(i);
			t[a2].push_back(t2);
			continue;
		}
		for(int j = 0;j < k;j++){
			int aa,tt;
			cin>>aa>>tt;
			if(T == 0) T = tt;
			if(T != tt) B = 0;
			a[aa].push_back(i);
			t[aa].push_back(tt);
		}
	}
	for(int i = 1;i <= m;i++){
		if(a[i].size() <= 1) continue;
		for(int j = 0;j < a[i].size();j++){
			for(int k = j + 1;k < a[i].size();k++){
				int u = a[i][j],v = a[i][k];
				h[u][v] = h[v][u] = min(h[u][v],t[i][j] + t[i][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(A){
			dfsA(x);
			cout<<dis[y]<<endl;
		} 
	}
	return 0;
}
