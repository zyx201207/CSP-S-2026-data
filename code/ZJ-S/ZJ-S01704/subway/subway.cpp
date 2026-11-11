#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,p,q;
int a[5001];
int g[5001][60001];
int d[5001][5001];
int k;
vector<int>v[5001];
int h[5001][5001];
int is(int x,int y){
	if(x==y)return 0;
	if(h[x][y])return h[x][y];
	int ans=LLONG_MAX;
	for(int i=0;i<v[x].size();i++){
		for(int j=0;j<v[y].size();j++){
			if(v[x][i]==v[y][j])ans=min(ans,g[x][v[x][i]]+g[y][v[y][j]]);
		}
	}
	return h[x][y]=ans;
}
void f(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],is(i,j));
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>p>>q;
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			g[u][i]=w;
			v[u].push_back(i);
		}
	}
	f();
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<d[l][r]+a[l]+a[r]<<endl;
	}
	return 0;
}
