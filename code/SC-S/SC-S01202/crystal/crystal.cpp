/*
感觉是一个贪心加两端维护简单题
首先对 a 排序，得到一个序列
然后容易得到如果我们选择一个区间变成全部相等，一定是先向左右两边的较接近值操作
所以容易写出 O(n^2) 暴力，期望40pts
那么我们考虑这个的底层变化逻辑，不难发现其实是区间赋值中位数
那么我们记录前缀和双指针即可解决

15min 写完但是坠机了，hack 自己ing

我是唐比，只能加不能减，这个向前二分最远可操作点就行了
半小时 T1 有点浪费了
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< int,int >
#define QWQ return 0;
#define QAQ return

const int N=5e5+10;

ll a[N], sum[N];

int main()
{
	freopen( "crystal.in","r",stdin );
	freopen( "crystal.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ); cout.tie( nullptr );
	int n;
	ll m;
	cin>>n>>m;
	for( int i=1;i<=n;i++ ) cin>>a[i];
	sort( a+1,a+n+1 );
	for( int i=1;i<=n;i++ ) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for( int i=1;i<=n;i++ )
	{
		int l=1, r=i;
		while( l < r )
		{
			int mid=l+r>>1;
			if( a[i]*( i-mid+1 )-( sum[i]-sum[mid-1] ) <= m ) r=mid;
			else                                              l=mid+1;
		}
		ans=max( ans,i-l+1 );
	}
	cout<<ans;
	QWQ
}