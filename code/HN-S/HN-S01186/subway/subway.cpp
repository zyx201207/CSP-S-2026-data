#include<bits/stdc++.h>
#define int long long

using namespace std;

const int INF=1e13;
int c,n,m,d,q,w[500010],k[505],a[505][500010],t[505][500010],dis[500010];
struct Edge{
	int x,w;
	bool operator <(const Edge& a)const{
		return w<a.w;	
	}
};
priority_queue<Edge,vector<Edge>,less<Edge> >que;
void dij(int x,int y){
	for(int i=1;i<=n;i++) dis[i]=INF;
	
}

signed main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
}
