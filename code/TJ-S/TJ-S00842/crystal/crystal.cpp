#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],pre[500005];

signed main(){
	cin.tie(0) -> ios::sync_with_stdio(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;++i)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;++i)
		pre[i] = pre[i - 1] + a[i];
	int f = 0;
	for (int i = 1;i <= n;++i){
		int l = 1,r = i,ans = i;
		while (l <= r){
			int mid = l + r >> 1;
			if ((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) > m)
				l = mid + 1;
			else ans = mid, r = mid - 1;
		}
		f = max(f,i - ans + 1);
	}
	cout << f;
} 
// Toooooo Hard! by 14:35 ( 5 min AC A)
