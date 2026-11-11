#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],a[200005],l,r,k[200005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[j] >> k[j];
		}
	} 
	for(int i = 1;i <= q;i++){
		cin >> l >> r;
		
	}
	return 0;
}
