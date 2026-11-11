#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,l,r;
long long ans,sum;
long long a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1,r=n;
	while (l<=r)
	{
		if (a[l]<a[r])
		{
			if (c[l]!=c[r])
				ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if (a[l]==a[r])
		{
			if (c[l]!=c[r])
				ans+=a[l];
			a[r]-=a[l];
			l++;
			r--;
		}
		else
		{
			if (c[l]!=c[r])
				ans+=a[r];
			a[l]-=a[r];
			r--;
		}
	}	
	cout<<ans<<"\n";
	return 0;
} 
