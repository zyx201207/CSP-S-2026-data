#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
long long gizt[500005];
bool ju[500005][25];
vector<pair<int,int>> a[505];//每条地铁经过的站点以及其到达大厅的路程
vector<pair<int,int>> e[500005];//每个站点可乘坐的地铁及其到达该地铁所在站台的路程
long long (int xi,int yi){
	long long ans=0;
	long long d[505];
	memset(d,ox3f,sizeof(d));
	for (auto (u,v) : e[xi]){
		d[u]=min(d[u],v);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>gizt[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int aij,tij;
			cin>>aij>>tij;
			a[i].push_back({aij,tij});
			e[aij].push_back({i,tij});
		}
	}
	for (int i=1;i<=q;i++){
		int xi,yi;
		cin>>xi>>yi;
		cout<<f(xi,yi);
	}
}

