#include<bits/stdc++.h>
using namespace std;

const int N=505;
const int M=5e5+5;
const int Q=1e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][M];
int t[N][M];
int x[Q],y[Q];

//int dfs(int x,int s,int y){
//	if(x==y){
//		return s;
//	}
//	dfs()
//}

int main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);

	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int r=1; r<=q; r++) {
		cin>>x[r]>>y[r];
	}

	for(int i=1; i<=1; i++) {
		int ans=0;
		ans+=w[x[i]];
		ans+=t[x[i]][x[i]];
//		ans=dfs(x[i],y[i]);
		ans+=w[y[i]];
		cout<<ans;
	}
	return 0;
}
