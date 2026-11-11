#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=1;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=1;
	while (r<=n){
		ll ops=a[r]*(r-l+1)-sum[r]+sum[l-1];
		if (ops>m)
			l++;
		else
			ans=max(ans,r-l+1),r++;
		//cout<<l<<' '<<r<<' '<<ops<<' '<<ans<<'\n';
	}cout<<ans;
	return 0;
}/*
对于一个区间（原数组已被排序），我们需要找到使总修改最小的一个数（中间值），若没有这个数，则
选择最近的一个，使用双指针维护区间，若......(~14:45)
不对，这个思路是错误的。
但随着右侧边界扩大，修改为相同的成本总是不减的。
O(n^2)(45pts):
考虑对于每一个连续区间都进行一次遍历，然后再统计使用当前数字需要多少成本。
设当前能量为x，位置为i，区间为[l,r]，则我们需要求((i-l)x-sum[i-1]+sum[l-1]-x[r-1]+sum[r]
-sum[i])的最小值。
也就是(2ix-sum[i-1]-sum[i])-(l+r)x的最小值。
-------------------------------------------------------
等一下，我读错题目了，这个只能增加，不能减少能量！(15:24)
还是使用双指针，但只需维护x(r-l+1)-sum[r]+sum[l-1]与m的大小关系：
若>m，则l++，否则r++，统计(r-l+1)的最大值。
Complete at:15:38
*/
