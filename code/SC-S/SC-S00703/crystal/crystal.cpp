#include<bits/stdc++.h>//T1最终答案 
using namespace std;
const int maxn = 5e5 + 55;
long long int n, m;
long long int a[maxn], sum_an, fand[maxn], ans;
long long int found(long long int staa){
	long long int l = staa, r = n;
	bool op = 0;
	for(;l <= r;){
		long long int mid = (l + r) / 2;
		long long nowf;
		nowf = a[mid] * (mid - staa + 1) - (fand[mid] - fand[staa - 1]);
//		cout << staa << " " << mid <<" " << nowf << " ss" << endl;
		if(nowf <= m){
			l = mid + 1, op = 1;
		}
		else r = mid - 1;
	}
//	cout <<staa << " " << r << " " << a[r] * (r - staa + 1) - (fand[r] - fand[staa - 1])<< endl;
	
	if(op) return (r - staa + 1);
	else return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ans = 1;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++){
		fand[i] = fand[i - 1] + a[i];
//		cout << fand[i];
	}
	for(long long int staa = 1;staa <= n;staa ++){
		ans = max(ans, found(staa)); 
	}	
	cout << ans;
	return 0;
}
/*
50pts显然：枚举起点并查询，n^2
优化到nolgn?:

或许二分答案？√
如何当下起点至今的ft？ 
*/