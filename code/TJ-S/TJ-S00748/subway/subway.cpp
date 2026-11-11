#include <bits/stdc++.h>
using namespace std;
long long am[100005];
long long an[1005][1005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>am[i];
	}
	int k;
	for(int i=1; i<=n; i++) {

		cin>>k;
		for(int j=1; j<=k*2; j++) {
			cin>>an[i][j];
		}
	}

	int x,y;
	long long lj=0;
	for(int i=1; i<=q; i++) {
		lj=0;
		cin>>x>>y;
		lj+=am[x];
		lj+=am[y];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=k*2; j++) {
				for(int z=x; z<=y; z++) {
					if(an[i][j]==z and j%2!=0) {
						lj+=an[i][j+1];
						//cout<<an[i][j+1]; 
					}
				}
			}
		}
		cout<<lj;
	}


	return 0;

}
