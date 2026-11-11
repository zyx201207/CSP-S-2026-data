#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+1;
int c,t;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
		}
		if(a[2]-a[1]>d){
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			if(a[i]+d+1<=a[n]){
				ans++;
			} 
		}
		cout << ans << "\n";
	}
	
	return 0;
}
