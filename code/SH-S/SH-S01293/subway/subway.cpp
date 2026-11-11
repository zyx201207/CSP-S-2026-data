#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int c,n,m,d,q,w[maxn],k[maxn],a[505][maxn],t[505][maxn],x,y,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		cin >> x >> y;
		ans = w[x] + w[y];
		cout << ans << '\n';
		for(int i = 1;i <= n;i++){
			if(t[i][x] && t[i][y]){
				ans += t[i][x] + t[i][y];
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
