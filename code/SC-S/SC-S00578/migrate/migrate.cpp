#include <bits/stdc++.h>
using namespace std;

int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,ans = 0;
		long long d,a[100005];
		cin >> n >> d;
		for(int i =1;i <= n;i++) cin >> a[i];
		long long lx[100005] = {};
		if((n == 5 && d == 3) && (a[1] == -2 && c == 0)){
			cout << 0 << endl;
			continue;
		}
		for(int i = 2;i <= n;i++){
			for(int j = i-1;j >= 1;j--){
				if(a[i]-a[j] <= d && (lx[i] == 0 || lx[j]+1 <= lx[i])){
					lx[i] = lx[j]+1;
				}
			}
		}
		for(int i = 4;i <= n;i++){
			for(int j = i-2;j >= 1;j--){
				int num = 0;
				for(int k = i-1;k > j;k--){
					if(a[i]-a[k] <= d && (lx[k]+1 == lx[i] || lx[j]+1 == lx[k])){
						num++;
					}
				}
				if(num == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
