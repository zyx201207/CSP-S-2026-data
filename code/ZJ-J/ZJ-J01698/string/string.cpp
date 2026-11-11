#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],k,l,ans;
char c[200010],lst;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		if(s>=l/2)k=i;
	}
	int i=1,j=n,t=0;
	while(i<=j)
	{
		if(c[i]!=c[j])
		{
			if(a[i]>=a[j])
			{
				ans+=a[j];
				a[i]=a[i]-a[j];
				a[j]=0;
			}
			else
			{
				ans+=a[i];
				a[j]=a[j]-a[i];
				a[i]=0;
			}
		}
		else
		{
			if(a[i]>=a[j])
			{
				a[i]=a[i]-a[j];
				a[j]=0;
			}
			else
			{
				a[j]=a[j]-a[i];
				a[i]=0;
			}
		}
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	return 0;
}
