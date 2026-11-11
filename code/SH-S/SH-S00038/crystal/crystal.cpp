#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n;i++) cin >> a[i];
	int cnt = 0;
	sort (a + 1,a + 1 + n);
	for (int j = n;j >= 1;j--){
		int tmp = a[j];
		int ans = 0,sum = 0,flag = 1;
		for (int i = j; i >= 1;i--){
			if (sum + abs(tmp - a[i]) > m) flag = 0; 
			if (!flag) break;
			sum += abs(tmp - a[i]);
			ans++;
		}
		cnt = max(cnt,ans);
	}
	cout << cnt;
	return 0;
} 
