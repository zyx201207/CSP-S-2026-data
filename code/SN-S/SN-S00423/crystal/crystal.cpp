#include<bits/stdc++.h>
using namespace std;
long long n,ans[500001],a[500001];
unsigned long long m;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n-1);
	for(int i=n-1;i>0;i--)
	{
		long long num=a[i]-a[i-1],m0=m;
		if(num>m){ans[i]=0;continue;}
		else
		{
			ans[i]=1;
			for(int j=i-1;j>=0;j--)
			{
				m0-=a[i]-a[j];
				if(m0<0)break;
				else ans[i]++;
			}
		}
	}
	sort(ans,ans+n-1,cmp);
	cout<<ans[0];
	return 0;
}
