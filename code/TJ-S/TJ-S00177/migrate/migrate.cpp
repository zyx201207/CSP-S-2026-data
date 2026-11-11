#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
void solve(){
	long long n, d;
	cin >> n >> d;
	for(long long i = 1;i<=n;i++) cin >> a[i];
	long long p = a[2]-a[1];
	if(d<=p){
		cout << 0 << "\n";
		return;
	}
	long long h = (d/p)+(d/p-1);
	cout << max(0ll,n-h) << "\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
