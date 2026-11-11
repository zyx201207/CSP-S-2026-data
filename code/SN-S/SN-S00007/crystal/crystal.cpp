#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long acf[500010];//差分 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	cout<<a[0]<<endl;
	for(int i=1;i<=n;i++)
	{
		acf[i] = a[i] - a[i-1];
//		cout<<acf[i]<<" ";
	}
	
//	cout<<-1-(-3)<<endl;
	long long ans = -1; 
	for(int i=1;i<=n;i++)//枚举每个起点 
	{
		//不会写二分了这是递推qaq，只能强制性优化了呜呜呜
		if(i+ans>n-i)   break;//后面已经压榨不出一个 大于ans的空间了 
		//以上是判断优化 
		long long cost = 0,maxn = 1;
		long long times = 1;
		for(int j=i+1;j<=n;j++)
		{
			cost += acf[j]*times;
//			cout<<cost<<" ";
			if(cost<=m)
			{
				maxn++;
			}
			else
			{
				break;
			}
			times++;
		}
		ans = max(ans,maxn);
	}
	
	cout<<ans<<endl;
	
	return 0;
}//整体复杂度是n2，不知道能骗到多少分了qaq 
