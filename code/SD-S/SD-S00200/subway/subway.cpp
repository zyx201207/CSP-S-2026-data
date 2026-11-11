#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int maxx,b[1001][1001],e[1001][1001],x,y,a[1001],zx[1001][1001];
vector<int>v[1001];
int f[1001][1001];
void dfs(int lx,int l,int z){
	if(z==y){
		maxx=max(maxx,l+a[b[lx][zx[lx][z]]]+e[lx][zx[lx][z]]);
		return;
	}
	if(l>f[lx][z]){
		return;
	}
	f[lx][z]=l;
	for(int i:v[z]){
		if(i==lx){
			dfs(lx,l+e[i][zx[i][z]],b[i][zx[i][z]+1]);
		}
		else{
			dfs(i,l+e[i][zx[i][z]]+e[lx][zx[lx][z]],b[i][zx[i][z]+1]);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		for(int j=1;j<=op;j++){
			cin>>b[i][j]>>e[i][j];
			v[b[i][j]].push_back(i);
			zx[i][b[i][j]]=j;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=inf;
			}
		}
		maxx=0;
		dfs(0,0,x);
		cout<<maxx+a[x]<<'\n';
	}
	return 0;
}
