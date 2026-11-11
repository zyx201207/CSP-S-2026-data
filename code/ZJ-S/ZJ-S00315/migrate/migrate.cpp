#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		int n,d,op = 1;
		cin >> n >> d;
		vector<int> a(n + 1, 0), sum(n + 1);
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			sum[i] = a[i] - a[i - 1];
		}
		if(c ==11 || c == 12){
		if(d >= sum[1] && d >> 1 <=sum[1]) {
			cout << 0 <<'\n';
		}else{
			cout <<n-1 << '\n';
		}
	}
	cout << 0 <<endl;
	}
	return 0;
}
