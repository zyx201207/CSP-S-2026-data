#include <iostream>
using namespace std;
int f[10005][10005],a[100005],n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[i][0] = 0;
	}
	f[1][1] = a[1];
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			f[i][j] = max(f[i - 1][j - 1] & a[i],f[i - 1][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		ans = max(ans,f[i][m]);
	}
	cout << ans << endl;
	return 0;
}
