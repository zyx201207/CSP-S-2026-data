#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long a[500001],diff[500001],sum[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long j = 1;j <= n;j ++){
		cin >> a[j];
	}
	sort(a+1,a+n+1);
	diff[1] = a[1];
	for(long long j = 2;j <= n;j ++){
		diff[j] = a[j]-a[j-1];
	}
	long long cnt = 1;
	sum[1] = 0;
	long long i,ans = 0;
	for(i = 2;i <= n;i ++){
		if(sum[i-1]>m){
			sum[i] = sum[i-1]-diff[i-1]*(cnt-1);
			cnt--;
			ans = max(ans,cnt);
			cnt = 1;
			sum[i] = 0;
			continue;
		}
		sum[i] = sum[i-1]+diff[i]*cnt;
		cnt++;
	}
	
	if(sum[n]>m){
		sum[n] -= diff[i]*(cnt-1);
		cnt--;
	}
	ans = max(ans,cnt);
	
	cout << ans;
	return 0;
}
