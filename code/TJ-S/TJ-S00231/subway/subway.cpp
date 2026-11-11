#include<bits/stdc++.h>
using namespace std;
int w[500005];//站点长度 
struct zhandian{
	int bh,ti;
};
struct zhandian2{
	int bh,wz;
};
vector<zhandian> k[505];//每条路线 
vector<zhandian2> t[500005];//每个站点的路线 
int zdcd[505];//路线长度 
long long s[1005][1005];//邻接表 
void dfs(int x,long long d){
	if()
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int n,m,d,q,c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>zdcd[i];
		for(int j=1;j<=zdcd[i];j++){
			int sdfg,hjkl;
			cin>>sdfg>>hjkl;
			k[i].push_back({sdfg,hjkl});
			t[sdfg].push_back({i,j});
		}
	}
	dfs(1,0);
	return 0;
}
