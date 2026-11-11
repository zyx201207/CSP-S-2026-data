#include<bits/stdc++.h>
using namespace std;
const long long MAX_N=5E5+78;
long long n,m,a[MAX_N],sum[MAX_N];
bool check(long long mid){
	/*
	  用mid个水晶，所用最小
	  代价看看会不会超m 
	*/
	long long min_dj=INT_MAX;
	for(long long i=mid;i<=n;i++){
		min_dj=min(min_dj,a[i]*mid-sum[i]+sum[i-mid]);
//		cout<<mid<<' '<<a[i]*mid<<' '<<sum[i]<<' '<<sum[i-mid]<<' '<<a[i]*mid-sum[i]+sum[i-mid]<<'\n';
	} 
	return min_dj<=m;
}
long long find(){
	long long l=0,r=n,ans=0,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		bool ok=check(mid);
		if(ok){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
//		cout<<sum[i]<<'\n';
	}
	cout<<find();
}
/*
对于一个序列，长为N，
若只能通过增加某元素使其
相等，则共进行|a1-aN|+|a2
-aN|+……次操作 
假定其有序，可化简为aN*N-sum[] 
二分？
预处理排序后1-i的代价
如果选择增加，不然白白浪费
一个位置，还要用相同
的代价。 
所以必须选择连续的区间，
于是可以进行前缀和
O（n）
check扫一遍即可？ 
*/
