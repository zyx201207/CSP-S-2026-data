//祝自己CSP-S二级……（显然毫无可能，今年第一题 * 都能做75吧（自己还不一定拿得到）），三级就不错了 
//顺便祝自己CSP-J二级（显然毫无可能，今年CSP-J有点简单的过分（可我不会T_T））
//all: 75- + 0 + 10- + 0 = 85- (保守估计：40，激进估计：85) 
//pre: 45 (@ 1-9) -> 75(@13-18)
#include <bits/stdc++.h>
using namespace std;
int n, maxn = 1;
long long m, p, a[500010];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	//预览所有题，思考思路……（30 min），似乎T1 T2较简单（贪心+图论）？ 
	//尝试使用暴力，直接 O(n ^ 2)，稳但很慢；正解想不到； 
	//那我们尝试分类：
	//对于所有的 n <= 5000，使用暴力； 
	//因为C16-18均有特殊性质保证等差，所以期望得50分； 
	//接下来，暴力写完，先搁置，看T2； 
	//=============================================================================
	//后面的似乎1分也拿不到，只能寄希望于此题，继续思考如何对等差数列； 
	//发现a[i] = i也是公差为1的等差数列，那么我们将C13-15也纳入讨论范围，期望75分； 
	//75分能二级吗？有可能不能，但试一试； 
	//列表（n = 5  m = 6） 
	//a[]: 1  3  5  7  9 
	//此时直接考虑让更多值变为9（考虑其他的也一样）； 
	//发现：7 -> 9 花费 2; 5 -> 9 花费 2 * 2，故ans = 3 (spend = 6)； 
	//发现：spend = p * (1 + 2 + 3 + ... + (n - 1))，且spend < m； 
	//每次让spend + p * i，枚举i，复杂度：O(n)，开始编代码
	//完成，这可能能拿75（或更低），自查：freopen(+) return 0;(+) 逻辑(+)
	//祝自己这题拿75 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if((i != 0 && i != 1) && a[i] - a[i - 1] != p) p = -1;
		else if(i == 1) p = a[i] - a[i - 1];
	}
	if(p != -1){
		int spend = 0, cnt = 1; 
		for(int i = 1; i < n; i++){
			if(spend + p * i > m) break;
			spend += p * i, cnt++;
		}
		cout << cnt;
		return 0;
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		long long ls = m;
		int mxn = 1;
		for(int j = i - 1; j >= 0; j--){
			if(ls >= a[i] - a[j]){
				mxn++;
				ls -= (a[i] - a[j]);
			} else break;
			maxn = max(maxn, mxn);
		}
	}
	cout << maxn;
	return 0;
}
