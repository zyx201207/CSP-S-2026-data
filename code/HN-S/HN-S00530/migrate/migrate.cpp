#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n,d,x,T,c,ans,a[2000050];

signed main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
		}
		if(n <= 3){
			cout << 0 << endl;
			continue;
		}
		x = a[2] - a[1];
		ans = 0;
		if(c <=  10){
			for(int i = 1;i <= n;i ++){
				for(int j = i + 1;j <= n;j ++){
					if(a[j] - a[i] <= d * 2){
						continue;
					}
					int f = 0;
					for(int k = i;k <= j;k ++){
						if(a[k] - a[i] <= d && a[j] - a[k] <= d){
							f ++;
						}
					}
					if(f == 2){
						ans ++;
					}
				}
			}
			cout << ans << endl;
		}
		else if(c <= 12){
			if(2 * x < d && 3 * x < d){
				cout << n - 3 << endl;
			}else{
				cout << 0;
			}
		}
	}
	return 0;
}

