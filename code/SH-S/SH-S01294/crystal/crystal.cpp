#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 5e5+100;
int n, m;
long long a[N], ans;
int main(){
	//输入 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	
	sort(a+1, a+1+n);
	 
	for(int i=n;i>=1;i--){
		//每次初始化 
		long long res = 1;
		long long ope = m;
		//特判：如果i<=ans,
		//那么即使前i个全选也无法产生比ans更多的选择，结束循环 
		if(i<=ans) break;
		//正式操作 
		for(int j=i-1;j>=1;j--){
			if(a[i] - a[j] <= ope){//可以操作 
				res++;
				ope -= a[i] - a[j];
			}
		}
		if(res>=ans) ans = res;
	}

	printf("%lld", ans);

	return 0;
}
