#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], sum[N];
int n, m, ans;
bool check(int j, int i){
	return (i - j + 1)  * a[i] - (sum[i] - sum[j - 1]) <= m;
}//将j到i提升到a[i]的花费是
/*
\sum_{k=j}^i a[i] - a[k]
= (j-i+1)a[i] - (sum[i]-sum[j-1]) 
*/ 
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 0, r = i + 1;
		while(l < r - 1){
			int mid = l + r >> 1;
			if(check(mid, i)) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}
/*
最后只能使用一样的，每次只能操作+1所以只能在排序后的数组依次拔高
设拔高到当前的位置所需要的sum 
 
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

*/
