#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

int a[32],b[N];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> b[i];
		int x = b[i];
		int j = 0;
		while(x){
			a[j] += (x & 1);
			x >>= 1;
			j++;
		}
	}
	int bns = 0;
	for (int i = 30;i >= 0;i--){
		if (a[i] >= m){
			bns += (1 << i);
		}
	}
	for (int i = 1;i <= n;i++){
		b[i] &= bns;
	}
	sort(b + 1,b + n + 1);
	int ans = b[n];
	for (int i = 2;i <= m;i++){
		ans &= b[n - i + 1];
	}
	cout << ans << endl;
	return 0;
}

