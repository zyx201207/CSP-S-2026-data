/*
很简单的 T1
简单思考了一下 
首先没有保证顺序所以排序
然后钦定某个 a_i 为要组成的数
由于 m 不一定要用完，所以这样搞是对的 
然后做一个双指针就行了
应该是黄色的。
exp:100pts
fin:14:42 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500050;
#define int long long
int n;
long long m,sum=0;
long long a[N];
int maxn;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		while(l<i&&(i-l+1)*a[i]-sum>m)
		{
			sum-=a[l];
			l++;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn<<'\n';
	return 0;
}