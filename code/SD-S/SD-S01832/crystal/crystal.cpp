#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans;
int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long i = 1, j = 2;
	long long sum = a[1] + a[2];
	while(j <= n && i <= j) {
		if(a[j] * (j - i + 1) - sum <= m) {
			ans = max(ans, j - i + 1);
			j++;
			sum += a[j];
		}
		else {
			sum -= a[i];
			i++;			
		}
	}
	cout << ans << endl;
	return 0;
}
