#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
long long n,m;
long long a[N],pre[N][N];
bool check(long long x){
	long long need = 0,sum = 0x3f3f3f3f;
	for(int i = 1;i <= n - x + 1;i++){//起点 
	need = 0;
		for(int j = i + 1;j <= i + x - 1;j++){//终点 
			need += pre[i][j];
		}
		sum = min(need,sum);
	}
	return sum <= m;
	
}
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	//先排序 
	sort(a+1,a+n+1,cmp);
	//先求出每两个数之间的差值(类似于区间dp)
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			pre[i][j] = abs(a[i] - a[j]);
		}
	} 
	//开区间二分
	long long l = 0,r = n + 1;
	while(l + 1 < r){
		long long mid = (l + r)/2;
		if(check(mid)) l = mid;
		else r = mid;
	} 
	cout << l;
	return 0;
}
