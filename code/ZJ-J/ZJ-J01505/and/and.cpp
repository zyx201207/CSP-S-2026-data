#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node {
	int num, boc;
} a[200001];
int n, m;
bool cmp(node x, node y) {
	if(x.boc == y.boc) return x.num > y.num;
	else return x.boc > y.boc;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i].num;
		int tmp = a[i].num;
		while(tmp) {
			if(tmp & 1) a[i].boc++;
			tmp >>= 1;
		}
	}
	sort(a, a + n, cmp);
	int ans = a[0].num;
	for(int i = 1;i < m;i++) ans = ans & a[i].num;
	cout << ans;
	return 0;
}
