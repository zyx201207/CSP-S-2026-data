#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, a[500000],t[500000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	int ans =0;
	for (int i = 1; i <= m; i++){
	    int w;
	    cin >> w;
	    if (w == d)
	        ans += w;
    } 
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
		    cin >> a[j] >> t[j];
		    if(t[j] == d)
		        ans+=t[j];
	    }
	}
	for (int i = 1; i <= q; i++){
		int x, y;
	    cin >> x >> y;
    }
    for (int i = 1; i <= q; i++)
        cout << ans;
	return 0;
}
