#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t > 0){
		long long a[1000005] = {0}, ans = 0;
		long long n, d;
		cin >> n >> d;
		for(long long i = 0;i < n;i++){
			cin >> a[i];
		}
		
		cout << ans << endl;
		t--;
	}
	return 0;
}
