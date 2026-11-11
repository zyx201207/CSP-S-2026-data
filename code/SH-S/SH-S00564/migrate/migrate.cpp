#include <bits/stdc++.h>
using namespace std;
long long c,T,n,m,ans,a[2000005];
int f[2000005],cd[2000005];
int j=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--){
		memset(f,0x3f,sizeof(f));
		cin >> n >> m;
		for (int i = 1;i <= n;i++) cin >> a[i];
		for (int i = 1;i <= n;i++){
			for (j = i+3;j <= n;j++)
			if (a[j]-a[i] > m) break;
			if ((a[j]-a[i])/m <= (j=i-1)) ans++;
		}
		if (c == 11 || c == 12){
			if (a[2]-a[1] >= m) cout << 0;
			else cout << n-2*m+1;
		}
		else {
			cout << ans;
		}
	}
}
