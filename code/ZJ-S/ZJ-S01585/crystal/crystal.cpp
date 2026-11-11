#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],f[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
	}
	for(int i=1,l=1;i<=n;i++)
	{
		while(f[i]-f[l-1]+m<(i-l+1)*a[i])
		{
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

