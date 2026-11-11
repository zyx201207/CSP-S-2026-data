#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int dp[500005];
int z[500005],st[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=2; i<=m; i++) {
		dp[i]=-1;
	}
	int k[505][d+2],a[500005];
	int t[505][d+2],b[500005];
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	int kk,tt,s;
	for(int i=1; i<=n; i++) {
		cin>>s;
		for(int j=1; j<=s; j++) {
			cin>>k[i][j]>>t[i][j];
			if(j==2){
				z[k[i][j-1]]=k[i][j];
				st[k[i][j-1]]=t[i][j]+t[i][j-1];
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int aaa,bbb;
		cin>>aaa>>bbb;
		cout<<st[aaa]+w[aaa]+w[bbb];
	}
	return 0;
}
