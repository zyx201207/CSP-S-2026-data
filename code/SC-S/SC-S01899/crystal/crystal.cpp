#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long n, m, a[N];

int ans;
long long s[N];

int Mid;
long long v[N];

int Find(int x, int R){
	int l = 1, r = R;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(v[mid] <= x) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; ++i){ 
		s[i] = s[i - 1] + a[i];
		if(Mid == 0 && a[i] <= 0 && a[i + 1] > 0) Mid = i;
	}
	
	for(int i = Mid; i >= 1; --i) v[Mid - i + 1] = s[i - 1];
	
	for(int i = 1, j = 1; i <= n; ++i){
		long long num = i * a[i] - s[i]; // 将前 i 个数全部变为 a[i] 的总代价
		if(num <= m){
			ans = max(ans, i - j + 1);
		}
		else{
			while(j + 1 <= i && num + s[j - 1] > m) j++;
			ans = max(ans, i - j + 1);
		}
	}
	cout << ans;
	return 0;
}
/*

最后一个样例老是过不了, 先看下一题

14:30 - 15:32

T1

题意

n 个数
可以进行最多 m 次操作
每次将任意一个数 + 1

求 进行最多 m 次操作后 最多能有多少个数相同

思路

不是, T1 题面这么短吗 ?

只能做加法, 不能做减法

排序后, 对于第 i 个数 a[i], 
将前 i - 1 个数全部变为 a[i] 的代价 w[i] = (i - 1) * a[i] - s[i - 1]
当 第一次 w[i] > m 时不合法, 答案为 i - 1

*/