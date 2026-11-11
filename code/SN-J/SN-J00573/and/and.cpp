#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],vis[N],f[N][2005],mxn;
int ans;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mxn=max(mxn,a[i]);
	}
	ans=a[1];
	for(int i=2; i<=n; i++) ans&=a[i];
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(n<=2000) {
		for(int i=1; i<=n; i++) f[i][0]=1;
		for(int i=1; i<=n; i++) f[i][1]=max(a[i],f[i-1][1]);
		for(int i=2; i<=n; i++) {
			for(int j=2; j<=i; j++) {
				f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
			}
		}
		cout<<f[n][m];
	}else cout<<mxn;
	return 0;
}
