#include <iostream>
#include <algorithm>
using namespace std;
void solve(){
	int n;
	long long d;
	cin >> n >> d;
	long long x[2000001];
	for(int i = 1;i <= n;i ++){
		cin >> x[i];
	}
	long long ans = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(abs(x[i]-x[j])==2) ans++;
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	} 
	return 0;
}
