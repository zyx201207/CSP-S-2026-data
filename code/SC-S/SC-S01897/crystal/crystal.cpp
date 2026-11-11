//重在参与，重在爆零-----我和我的同学 
#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
		if(f[i]>m)
		{
			cout<<i-1;
			return 0;
		 } 
	}
}