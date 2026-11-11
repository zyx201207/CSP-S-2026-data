#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],a[505][125255],x,y;
long long w[125255],t[505][125255],ans;
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
    	cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		ans=w[x]+w[y];
		cout << ans << endl;
	}
	return 0;
}
