#include<bits/stdc++.h>
using namespace std;
const int M=5e3,N=500,Q=20;
long long c,n,m,d,q,w[M+5],k[M+5],a[M+5][Q+5],t[M+5][Q+5],res[M+5][M+5],ans[M+5][M+5];
vector<pair<long long,long long> >g[N+5];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=5e3; i++) {
		for(int j=1; j<=5e3; j++) {
			res[i][j]=1e15;
			if(i==j)res[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)cin>>a[i][j]>>t[i][j];
		for(int j=1; j<=k[i]; j++) {
			for(int h=1; h<=k[i]; h++) {
				long long W=t[i][j]+t[i][h];
				g[a[i][j]].push_back(make_pair(a[i][h],W));
				g[a[i][h]].push_back(make_pair(a[i][j],W));
				res[a[i][j]][a[i][h]]=min(res[a[i][j]][a[i][h]],W);
				res[a[i][h]][a[i][j]]=min(res[a[i][h]][a[i][j]],W);
			}
		}
	}
//	for(int i=1; i<=m; i++) {
//		for(int j=1; j<=m; j++) {
//			cout<<res[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1; k<=m; k++) {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=m; j++) {
				if(res[i][k]+res[k][j]<res[i][j]) {
					res[i][j]=res[i][k]+res[k][j];
				}
			}
		}
	}
//	for(int i=1; i<=m; i++) {
//		for(int j=1; j<=m; j++) {
//			cout<<res[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int x,y;
	for(int i=1; i<=q; i++) {
		cin>>x>>y;
		ans[x][y]=w[x]+w[y]+res[x][y];
		cout<<ans[x][y]<<endl;
	}
	return 0;
}

