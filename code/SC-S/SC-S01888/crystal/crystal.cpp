#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool check(int mid)
{
	int sum=0;//sum:当前区间的每一个元素到右端点的距离和
	//每向右滑动一格:sum=sum-滑动前i到i+mid-1的距离+(mid-1)*滑动后i+mid-1到i+mid-2的距离
	//初始化
	for(int i=1;i<=mid-1;i++)
		sum+=a[mid]-a[i];
	if(sum<=m)
		return true;
	for(int i=2;i<=n-mid+1;i++)
	{
		sum=sum-(a[i+mid-2]-a[i-1])+(mid-1)*(a[i+mid-1]-a[i+mid-2]);
		if(sum<=m)
			return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,mid,ans;
	while(l<=r)
	{
		mid=(__int128_t)(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
//一定只会对相邻的若干个水晶进行操作
//问题变为：找到使得每一个元素到右端点的距离和<=m的最大区间
//二分答案：判断区间长度==mid时距离和能否<=m