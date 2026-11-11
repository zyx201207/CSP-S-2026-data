#include <bits/stdc++.h>
using namespace std;
long long  m; //m只是参与比较，不能作为变量
long long a[500005];
long long sum[500005];
int n, ans;

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//若要循环，最多一层
	stable_sort(a + 1, a + n + 1);//输入无序，构建前缀和要有序数组
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
	}//构建sum前缀和数组
	for (int i = 1; i < n; i++) {//若用i表示当前可以合成的总水晶数
		if (   a[i] * (i - 1) - sum[i - 1] <= m  ) {
			ans = max(ans, i);
		}
	}
	cout << ans ;


	return 0;
}