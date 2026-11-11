//姓名:陆坦仪
//学校:西安市第三中学 
//考号:SN-S00524
#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
long long n,m,a[N] = {},mx = LONG_LONG_MIN,mn = LONG_LONG_MAX,ans1 = 0,ans2 = 0;
pair<long long,int>mos,mid;//most mid 分别表示众数和中位数 most.first为众数值 .second为众数个数
//mid.first为中位数值 .second为中位数坐标 
int mos_p;//众数的坐标 
long long ans = LONG_LONG_MIN;
long long f(long long x){
	if(x < 0)return -x;
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int t;
		scanf("%lld",&t);
		a[i] = t;
	}
	bool flag = true;
	for(int i = 1;i <= n;i++){
		if(a[i] != i){
			flag = 0;
			break;
		}
	}
	if(flag){
		//满足特殊性质A
		int sumq = 0,qqq = 0;
		while(sumq < m){
			sumq += q11;
			qqq++;
		}
		qqq--;
		if(qqq < n){
			cout << qqq;
		}else{
			cout << n;
		}
		return 0; 
	}
	int cnt = 0;
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		cnt = 0;
		long long k;//基准值
		long long m1 = m;
		for(int j = i;j >= 1;j--){
			if(j == i){
				cnt++; 
				k = a[i];
				continue;
			}
			long long del = f(a[i] - a[j]);
			if(del <= m1){
				m1 -= del;
				cnt++;
			}else{
				break;
			} 
		}
		if(ans < cnt){
			ans = cnt;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
