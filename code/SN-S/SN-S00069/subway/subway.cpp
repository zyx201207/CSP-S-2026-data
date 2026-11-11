#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],a[501][500001],t[501][500001],w[500005],x[100001],y[100001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) cin >> a[k[i]][j] >> t[k[i]][j];
	}
	for(int i = 1;i <= q;i++) cin >> x[i] >> y[i];
	if(n == 1){
		for(int i = 1;i <= q;i++) cout << w[x[i]] + w[y[i]] + t[1][x[i]] + t[1][y[i]] << "\n";
		return 0;
	}
	if(n == 2){
		for(int i = 1;i <= q;i++)
		{
			int t1 = x[i],t2 = y[i];
			a[]
		}
	}
	return 0;
}
