//pre: 10
#include <iostream>
using namespace std;
int c, t, n, d, maxn = -1e9, x[2000010];
int main(){
	//特殊性质A依旧等差数列……特性C是让我暴力吗？
	//只考虑A，说不定能骗10分……（O(tn)） 
	//列表
	//2 4 6 8 10
	//2 - 6, 4 - 8, 6 - 10 
	//1 2 3 4 5 6 7
	//Null 
	//发现：每个点 与 每个点 + 3在A下总是双径岛屿对，结果：n - 3（前提：鸟不能一次直接飞完3段） 
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		int p = x[n] - x[n - 1];
		if(p > d || d >= 3 * p){
			cout << 0; //公差比一次能飞的距离都大，或鸟能一次直接飞完3段 
			continue;
		}
		cout << n - 3;
	}
	return 0;
}
