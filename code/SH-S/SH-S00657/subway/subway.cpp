#include <bits/stdc++.h>
using namespace std;
struct route{
	int v,time;
};
int a[500009];
vector<route> to(500009);
bool vst[500009];
int dist[500009];
int dfs(int start,int end,int res){
	vst[start] = true;
	for(int i=0; i<sizeof(to[start]); i++){
		int u = to[start].v;
		if(vst[u] == true){
			return 0;
		}
		if(to[i].v==end){
			return res;	
		}
		res+=to[i].time;
		dfs(u,end,res);
		res-=to[i].time;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=0; i<m; i++){
		cin >> a[i];
	} 
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		int pa[509];
		int t[509];
		for(int j=0; j<n; j++){
			cin >> pa[j] >> t[j];
		}
		for(int x=0; x<num; x++){
			for(int y=x+1; y<num; y++){
				to[pa[x]].v = pa[y];
				to[pa[x]].time = t[x]+t[y];
				to[pa[y]].v = pa[x];
				to[pa[y]].time = t[x]+t[y];
			}
		}
	}
	for(int i=0 ; i<q; i++){
		int u,v;
		cin >> u >> v;
		cout << a[u]+a[v] + dfs(u,v,0) << endl;
	}
	return 0;
}

