#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;

int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int ans = 0,s = 0;
	for (int i = 1,j = 1;j <= n;j++){
		s += (j - i) * (a[j] - a[j - 1]);
		while (s > m){
			s -= (a[j] - a[i]);
			i++;
		}
		ans = max(ans,j - i + 1);
	}
	cout << ans << endl;
	return 0;
}

