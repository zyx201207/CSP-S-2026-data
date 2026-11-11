//wangji zuiduanlu zem xie le www
#include<bits/stdc++.h>
using namespace std;
struct stu{
	int v,w;
};
int ans1=1e18;
vector<bool> vis;
void dfs(int u,int a,int ans,const vector<vector<stu> > &gr){
	if(u==a){
		ans1=min(ans1,ans);
		return;
	}
	for(auto v:gr[u]){
		if(vis[v.v]==0){
			vis[v.v]=1;
			ans+=v.w;
			dfs(v.v,a,ans,gr);
			vis[v.v]=0;
			ans-=v.w;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> kt(m+5,0);
	for(int i=1;i<=m;i++){
		cin>>kt[i];
	}
	vector<vector<stu> > gr(n+m+5);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			gr[m+i].push_back({a,t});
			gr[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,r;
		cin>>x>>r;
		ans1=1e18;
		vis.assign(n+m+5,0);
		dfs(x,r,0,gr);
		cout<<ans1+kt[x]+kt[r]<<'\n';
	}
	


	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/