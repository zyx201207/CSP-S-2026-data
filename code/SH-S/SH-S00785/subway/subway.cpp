#include<bits/stdc++.h>
using namespace std;
int eee,n,m,d,q,ans=0;
int a[500005],w[500005];
int c[500005][2];
struct B {
	int t;
} b[500005][500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>eee>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>a[i];
	}


	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		w[i]=k;
		for(int j=1; j<=k; j++) {
			int s;
			cin>>s>>b[i][s].t;
			c[i][j]=s;
		}
	}
	while(q--) {
		int kai,en;
		ans=0;
		cin>>kai>>en;
		ans+=a[kai];
		ans+=a[en];
		if(n==2) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=2; j++) {
					if(c[i][1]==kai and c[i][2]==en) {
						int s=c[i][1];
						ans+=b[i][s].t;
						int k=c[i][2];
						ans+=b[i][k].t;

					}
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=w[k];j++){
					if(c[i][j]==en){
						ans+=b[i][c[i][j]].t;
						for(int r=1;r<=w[k];r++){
							if(c[i][r]==kai)ans+=b[i][c[i][r]].t;
						}
					}
				}
			}
		}
	}

	cout<<ans;
	return 0;
}
