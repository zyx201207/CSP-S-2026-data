#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	
	vector<long long> tot, num;
	long long ans = 0;
	int cnt = -1;
	for(int i = 1; i <= n; i++){
		if(i == 1) {
			++cnt;
			num.push_back(a[i]);
			tot.push_back(1);
		}else if(a[i] == a[i - 1]) {
			++tot[cnt];
		}else{
			++cnt;
			num.push_back(a[i]);
			tot.push_back(1);
		}
	}
	for(int i = 0; i <= cnt; i++){
		long long total = tot[i], op = 0;
		for(int j = i - 1; j >= 0; j--) {
			long long x = abs(a[i] - a[j]);
			if(x * tot[j] + op <= m) {
				op += x * tot[j];
				total += tot[j];
			}else{
				total += (m - op) / x;
				break;
			}
		}
		ans = max(ans, total);
	}
	cout << ans;
	return 0;
}
