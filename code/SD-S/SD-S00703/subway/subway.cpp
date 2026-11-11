#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=5e5+10;
int c,n,m,k[N],d,q,a[510][500*500+10];
long long w[N],t[510][500*500+10];
struct node {
	int to,
};
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>k;
		for (int j=1;j<=k;j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
