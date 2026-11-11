#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 6;
int c,T,n,d;
int a[N],dist[N],f[N];
void trickA(){
	int gc = a[2] - a[1];
//	cout << d << " " << gc << " ";
	if(d / gc <= 1){
		cout << 0 << "\n";
		return;
	}
	int d1 = 1,ans = 0;
	while(d1 < n && a[d1 + 1] - a[1] <= d) d1++;
	for(int i = 1;i <= n;i++){
		ans += max(min(n,i + 2*d1 - 2) - min(n,i + d1 - 1) - 1,0ll);
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		if(c == 11 ||c == 12){
			trickA();
			continue;
		}
		a[n + 1] = 1e18;
		for(int i = 1;i <= n;i++){
			for(int j = i - 1;j <= n;j++){
				dist[j] = 1e18;
				f[j] = 0;
			}
			dist[i] = 0;f[i] = 1;f[i + 1] = -1;
			int near = i,farth = i;
			for(int u = i;u <= n;u++){
				if(f[u] > 2) break;
				f[u] += f[u - 1];
//				for(int j = i;j <= n;j++){
//					cout << f[j] << " ";
//				}
				ans += (f[u] == 2);
				while(farth < n && a[farth + 1] - a[u] <= d){
					farth++;
					dist[farth] = dist[u] + 1;
				}
				while(near <= n && dist[near] < dist[u] + 1){
					near++;
				}
				f[near] += f[u],f[farth + 1] -= f[u];
//				cout << near << " ";
			}
//			cout << "\n";
		} 
		cout << ans << "\n";
	}
	return 0;
}

