#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
int n;
ll m;
ll a[N],pre[N];
/*
当从小到大排序时，显然可以有补连续的区间一定比不连续的区间更优
但是如果二分补后的结果，有hack数据-100,-90,1,2,3
但是时间复杂度显然是给nlogn的，所以仍然考虑二分
可否二分枚举连续的区间？
循环左端点--> n
二分找右端点 --> logn
check？
计算对应区间的所需补成最高的所需的次数
有次数sum=区间最大高度×区间长度-区间和
可以用前缀和维护
复杂度O(nlogn)
并且刚好前缀和不会超longlong
*/
bool check(int l,int r){
	int len=r-l+1;
	ll sum_x=pre[r]-pre[l-1];
	ll sum=a[r]*len-sum_x;
	if(sum>m) return false;
	else return true;
}
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid;
		while(l<r){
			mid=(l+r+1)>>1;
			if(check(i,mid)) l=mid;
			else r=mid-1;
		}
		ans=max(ans,(l-i+1));
	}
	cout<<ans;
	return 0;
}