#include <bits/stdc++.h>
using namespace std;
int ddp[20001][20001],a[200050];


int main() {
	freopen ("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	cin>>n>>m;


	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	ddp[0][0]=0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=min(m,i); j++) {
			if(j-1==0) {
				ddp[i][j]=a[i];
			} else {
				ddp[i][j]=ddp[i-1][j-1]&a[i];
			}
			ddp[i][j]=max(ddp[i-1][j],ddp[i][j]);

		}

	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ddp[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=m; i<=n; i++) {
		ans=max(ans,ddp[i][m]);
	}
	cout<<ans;

    
    

	return 0;
}
