#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=5e5+100;
const ll inf=1e18;
int c,n,m,ddd,q;
ll d[601][601];
ll aw[N];
struct inm{
	int v;
	ll c;
};
vector<inm>g[N+600];
void add(int u,int v,ll c){
	g[u].emplace_back((inm){v,c});
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>ddd>>q;
	for(int i=1;i<=m;i++){
		cin>>aw[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,c;
			cin>>v>>c;
			add(i+m,v,c);
			add(v,i+m,c);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=inf;
		}
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(inm j:g[i]){
			for(inm k:g[i]){
				if(j.v==k.v)continue;
				d[j.v-m][k.v-m]=min(d[j.v-m][k.v-m],j.c+k.c);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		ll ysc=inf;
		cin>>u>>v;
		for(inm i:g[u]){
			for(inm j:g[v]){
				ysc=min(ysc,d[i.v-m][j.v-m]+i.c+j.c);
			}
		}
		cout<<(ysc+aw[u]+aw[v])<<'\n';
	}
	return 0;
}
/*
g++ -std=c++14 -O2 -Wall -o subway subway.cpp
time ./subway<subway.in>subway.out
*/