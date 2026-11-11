#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>e[2000010]; 
int vis[2000010];
int minn=2e9;
int c,n,m,d,q;
void dfs(int x,int v,int d){
	if(x==v){
		minn=min(minn,d);
		return ;
	}
	for(auto mas:e[x]){
		int it=mas.first,w=mas.second;
		if(!vis[it]){
			vis[it]=1;
			dfs(it,v,d+w);
			vis[it]=0;
		}
	}
}
int gtt(int x){
	return m+x;
}
int gte(int x,int i){
	return 2*m+n*x+i;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		e[i].push_back({gtt(i),w});
		e[gtt(i)].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k,la,lt;
		cin>>k;
		cin>>la>>lt;
		e[gte(la,i)].push_back({gtt(la),lt});
		e[gtt(la)].push_back({gte(la,i),lt});
		for(int j=2;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[gte(a,i)].push_back({gte(la,i),0});
			e[gte(la,i)].push_back({gte(a,i),0});
			e[gte(a,i)].push_back({gtt(a),t});
			e[gtt(a)].push_back({gte(a,i),t});
			la=a;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		minn=2e9;
		dfs(x,y,0);
		cout<<minn<<"\n";
	}
	return 0;
}


