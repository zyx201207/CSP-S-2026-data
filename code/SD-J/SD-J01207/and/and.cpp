#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
	long long a[N],f[N][N]; 
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=m;j++) {
			f[i][j]=max(f[i-1][j],f[i-1][j]&a[i]);
		}
	}
	cout<<f[n][m];
	
	
	return 0;
}
