#include<bits/stdc++.h>
using ll=long long;
using namespace std;
struct p{
	int x,v;
};
int o[500005];
int u[505];
ll h[505][505];
vector<p>a[500555];
int b[500005];
int f(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		cin>>u[i];
		for(int j=0;j<u[i];j++){
			int x,y;
			cin>>x>>y;
			o[x]++;
			a[500000+i].push_back({x,y});
			a[x].push_back({500000+i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)h[i][j]=i==j?0:2e9;
	}
	for(int x=1;x<=m;x++){
		if(o[x]>1){
			for(int j=0;j<a[x].size();j++){
				int s=a[x][j].v;
				for(int k=j+1;k<a[x].size();k++){
					int n1=a[x][j].x-500000;
					int n2=a[x][k].x-500000;
					h[n1][n2]=h[n2][n1]=(ll)s+a[x][k].v;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(h[j][i]+h[i][k]<h[j][k])
				h[j][k]=h[j][i]+h[i][k];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll z=2e18;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				z=min(z,(ll)h[a[x][i].x-500000][a[y][j].x-500000]+(ll)a[x][i].v+a[y][j].v);
			}
		}
		cout<<z+b[x]+b[y]<<'\n';
	}
	return 0;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	f();
	return 0;
}
