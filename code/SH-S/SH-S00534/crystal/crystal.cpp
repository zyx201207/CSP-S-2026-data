#include <bits/stdc++.h>
using namespace std;
const int MaxN = 5e5+100;
int n;
long long m;
long long a[MaxN];
long long pre[MaxN]; 
long long ans = 1;

bool check(long long j, long long i){
//	printf("check j=%lld,i=%d\n",j,i);
	long long len = (i-j+1);
	long long tg = len*a[i];
	long long sum = pre[i] - pre[j-1];
	long long diff = tg-sum;
//	printf("len=%lld,tg=%lld,sum=%lld,diff=%lld\n",len,tg,sum,diff);
	return diff<=m;
}

void solve(long long x){
//	printf("solve x=%d\n",x);
	long long l = 1, r = x;
	long long pos=x;
	while(l<=r){
		long long mid = l+(r-l)/2;
		if(check(mid,x)){
			r=mid-1;
			pos = mid;
		}else{
			l=mid+1;
		}
	}
	long long res = (x-pos+1);
	ans = max(ans,res);
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i-1] + a[i];//suffix
	}
	for(int i = 1; i <= n; i++)solve(i); 
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
6 3
1 2 10 999 999 1000

*/
