#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
int ans[500005];
long long sum;
int mx;


long long dfs(int t, int p) { //切分点
	long long r = 0;
	for (int i = p; i < t; i++) {
		r = r - a[i] + a[t];
	}
	return r;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 10000) {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			int l = 1, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				sum = dfs(mid, i);
				if (sum > m) {
					r = mid - 1;
				} else {
					l = mid;
				}
			}
			int mid = (l + r + 1) / 2;
			sum = dfs(mid, i);
			if (sum > m) {
				mx = max(mx, mid - i);
			} else {
				mx = max(mx, mid - i + 1);
			}
		}
		cout << mx;
	} else {
		long long x = abs(a[2] - a[1]); //差值
		int ans = 1;
		for (long long i = 1; i <= n; i++) {
			if (m >= x * i) {
				ans++;
				m = m - i * x;
			} else {
				break;
			}
		}
		cout << ans;
	}
	return 0;
}

/*起码也要做出第一道题目吧

<你的前三道题目只有第一个测试点>

<你的分数增加7>

我说能结束的是优质二分

疑虑了

悔恨了

新生之喜了

小猪乔治 小狗丹尼 小猫凯蒂 小羊苏西 小兔瑞贝卡 小马佩德罗 老鼠曼迪 小驴蒂芬

发YN抽象大赛时记得帮我查下小象是什么谢谢(

*/