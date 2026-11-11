#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+8;
long long c,t;
long long n,d,a[N];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(long long i=1;i<=n;i++){
			cin >> a[i];
		}
		if(a[n]-a[1]<=d){
			cout << 0 << endl;
			continue;
		}
		long long ans = 0;
		for(long long i=4;i<=n;i++){
			if(a[i]-a[i-3]>d&&a[i]-a[i-1]<=d){
				if(a[i-1]-a[i-2]<=d&&a[i-2]-a[i-3]<=d)ans++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}  
