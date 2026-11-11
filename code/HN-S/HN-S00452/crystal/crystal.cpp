#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
bool check(int x){
	int res = 0,last;
	int l = 2,r = x+1;
	for (int i = 1;i <= x;i++) res += a[x]-a[i];
	last = res;
	while (r <= n){
		int sum = last-(a[r-1]-a[l-1]);
		sum += (a[r]-a[r-1])*x;
		res = min(res,sum);
		last = sum;
		l++,r++;
	}
	return res <= m;
}
signed main(){
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l = 1,r = n+1,mid;
	while (l+1 < r){
		mid = (l+r) >> 1;
		if (check(mid)) l = mid;
		else r = mid; 
	}
	cout << l;
	return 0;
}//只能相加，不能相减 
//根据数据范围：O(n) / O(n log n)
//根据 nlogn 推出二分 
//二分合成的水晶个数 
//滑动窗口 O(n) * 二分 O(log n) -> O(n log n) 
