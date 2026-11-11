#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int MAXN = 5 * 1e5 + 5;
int a[MAXN];
int f[MAXN];
int zhi(int i, int j) {
	return f[j] - f[i - 1];
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	cin >> n >> m;
	for(int i = 1;i <= n; ++i) {
		 cin >> a[i];
	}
	sort(a + 1, a + 1 + n);//检查 
	for(int i = 1;i <= n; ++i) {
		f[i] = f[i - 1] + a[i];
	}
	int ji = -2e9;
	for(int i = 1;i <= n; ++i) {
		for(int j = i + 1;j <= n; ++j) {
			int k = zhi(i, j);
			k += m;
			if(k % (j - i + 1) == 0) {
				int chu = k / (j - i + 1);
				int ji1 = j - i + 1;
				if(a[j] <= chu) {
					ji = max(ji, ji1);
				}
			} 
			else {
				int chu = k / (j - i + 1);
				int ji1 = j - i + 1;
				if(a[j] < chu) {
					ji = max(ji, ji1);
				}
			}
		}
	}
	cout << ji;
	return 0;
}