#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m;
int ans=1;
long long a[5*N],sum[5*N];
bool check(int i,int x)
{
	long long num=m+sum[x]-sum[i-1];
	long long geshu=x-i+1;
	num/=geshu;//该段加上m后的平均数
	if(num>=a[x])//从i到j这一段都可以被用
	{
		return 1;
	} 
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);//记得改txt为in 
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;++i)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i = 1;i<=n;++i)
	{
		int l=i-1,r=n+1;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(check(i,mid))
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
} 