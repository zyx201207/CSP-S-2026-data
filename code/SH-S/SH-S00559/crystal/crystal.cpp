#include <iostream>
#include <cstring> 
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n; ll m;
ll a[N], d[N];
ll cnt[N];
ll dp[N];


int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + 1 + n);

	
	
	for (int i = 1; i <= n; i++){
		d[i] = a[i] - a[i - 1];
	}
	
	ll cnt1 = 1;
	ll num = 0;
	for (int i = 2; i <= n; i++){
		if (num + d[i] * cnt1 <= m){
			num += d[i] * cnt1;
			cnt1++;
		} else {
			break;
		}
	}
	cnt[1] = cnt1;
	dp[1] = num;
	// cout << cnt1 << " " << num << endl;
	
	// 这里只求出从第一个开始算的最大水晶数
	// 需要递推
	
	for (int i = 2; i <= n; i++){
		// 第i-1个的贡献去掉 
		dp[i] = dp[i - 1] - (a[cnt[i - 1] + i - 2] - a[i - 1]);
		// cout << dp[i] << " ";
		cnt[i] = cnt[i - 1] - 1;
		for (int j = cnt[i - 1] + i - 1; j <= n; j++){
			if (dp[i] + d[j] * cnt[i] <= m){
				dp[i] += d[j] * cnt[i];
				cnt[i]++;
			} else {
				break;
			}
		}
	}
	//cout << endl;
	
	ll ans = -1;
	for (int i = 1; i <= n; i++){
		ans = max(ans, cnt[i]);
		//cout << cnt[i] << " ";
	}	
	//cout << endl;
	
	cout << ans << "\n";
	
	return 0;
} 
