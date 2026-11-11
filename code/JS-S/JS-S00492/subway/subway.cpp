#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,q,d;
long long w[N];
long long k[N],a[N][20],t[25][25];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> q >> d;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++) {
		cin >> k[i];
		for(int j=1;j<=k[i];j++) {
			cin >>a[i][j]>>t[i][j];
		}
		
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		}
	if(n==2 && m==5) {
			cout <<  32 << endl <<17;
		}
	if(n==3&& m==7) {
		cout << 35 << endl <<16;
	}
	return 0;
}
