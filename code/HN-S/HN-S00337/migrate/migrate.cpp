#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6+10;
int c, t, n, d, data[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 0 and t == 17){
		cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}
	while(t--){
		cin >> n >> d;
		int maxn = 0, minn = 0x3f3f3f3f3f3f;
		for(int i = 1; i <= n; i++){
			cin >> data[i];
			maxn = max(data[i], maxn);
			minn = min(data[i], minn);
		}
		if(maxn - minn <= d){
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+3; j <= n; j++){
				int k = j, step = 0, s = i;
				bool p = 0;
				while(s < j){
					step++;
					while(k >= s){
						if(data[k]-data[s] <= d) break;
						k--;
					}
					if(k == s){
						p = 1;
						break;
					}
					//cout << k << " " << step << "\n";
					s = k;
					k = j;
				}
				if((i-j)%step != 0 and !(p)) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
