#include<bits/stdc++.h>
#include<windows.h> 
#define pb push_back
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define zxh(x, y, z, qwq) for(int qwq = x; qwq <= y; qwq += z)
#define dxh(x, y, z, qwq) for(int qwq = x; qwq >= y; qwq -= z)
using namespace std;

const int MAXN = 5e5 + 10;
bool flag = true, flag2 = true;
int n, m, a[MAXN], bx = 0, sum[MAXN], chah[MAXN];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int cha;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(i == 2) cha = a[i] - a[i - 1];
		if(i >= 2) {
			if(a[i] - a[i - 1] != cha) flag2 = false;
		}
		if(a[i] != i) flag = false;
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++) {
		chah[i] = chah[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	if(flag) {
		for(int i = 1; i <= n; i++) {
			if(m < sum[i]) {
				cout << i;
				return 0;
			}
		}
	}
	if(flag2) {
		for(int i = 1; i <= n; i++) {
			if(chah[i] == m) {
				while(chah[i + 1] == chah[i]) i++;
				cout << i;
				return 0;
			}
		}
		zxh(1, n, 1, i) {
			if(chah[i] > m) {
				cout << i - 1;
				return 0;
			}
		}
	}
//	for(int i = 1; i <= n; i++) cout << a[i] << endl;
	for(int i = 2; i <= n; i++) {
		if(chah[i] <= m) bx = i;
		if(chah[i] > m) break;
	}
	cout << bx;
	return 0;
}
/*
T1敢不敢赌75pts
拿山东二等
来
本质蒟蒻，能拿二等我就谢天谢地了 

RP++
弥园园!寿来，寿来 
*/
