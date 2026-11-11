#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans;
const int N=5e5+10;
int w[N];
int a[5100][5100],t[5500][5500];
int k;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--) {
		int u,v;
		cin>>u>>v;
		int flag1=0,flag2=0;
		//	if(d<=2) {
		for(int i=1; i<=n; i++) {
			flag1=0,flag2=0;
			for(int j=1; j<=k; j++) {
				if(a[i][j]==u)flag1=1;
				if(a[i][j]==v)flag2=1;
				if(flag1&&flag2) {
					long long ans=w[u]+t[i][u]+t[i][v]+w[v];
					cout<<ans<<"\n";
					i=n+1;
					break;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			ans+=w[u];
			for(int j=1; j<=k; j++) {
				long long ans=ans+t[i][j];
			}

		}
		cout<<ans<<"\n";
		//	}
		//else {
	}
	//}
	//3534639215feb268af6b618e02f29330
	return 0;
}
