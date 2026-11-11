#include <bits/stdc++.h>
using namespace std;


int n, m, a[500005], res;

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);

	int lastusem; // 上一次选水晶花了多少次操作
	int lastres; // 上一次选到了第几个水晶
	for (int i = 0; i < n - 1; i++) { // 从最大的开始选，看能不能合成
		int nowm = m; // 目前还剩几次操作
		int nowres = 1; // 目前有几个相等的水晶
		if (i == 0) { // 第一个石头只能直接算
			for (int j = i + 1; j < n; j++) { // 依次往后选
				if (nowm >= (a[i] - a[j])) { // 当前剩余次数必须大于需要的次数
					nowm -= a[i] - a[j];
					nowres++; // 加上这个水晶
				} else { // 否则后面所有水晶肯定都用不了
					break;
				}
			}
		} else if (a[i] == a[i - 1]) { // 如果和上一个相等那就不用算，直接继承
			lastres--; // 但是能合成的变少了
			continue; // 直接跳过
		} else { // 后面的石头能继承
			nowres = lastres - 1; // 至少能合成到这里
			nowm = m - lastusem + (a[i - 1] - a[i]) * (lastres - 1); // 这次合成到原来的数量能少花费一点
			for (int j = i + lastres - 1; j < n; j++) { // 到 i + lastres - 2 绝对能合成
				if (nowm >= (a[i] - a[j])) { // 当前剩余次数必须大于需要的次数
					nowm -= a[i] - a[j];
					nowres++; // 加上这个水晶
				} else { // 否则后面所有水晶肯定都用不了
					break;
				}
			}
		}
		// 为继承变量赋值
		lastusem = m - nowm;
		lastres = nowres;
		res = max(res, nowres); // 选用更大的
		if (res >= (n - i - 1))
			break; // 后面再多也超不过这个结果，结束
	}

	cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
