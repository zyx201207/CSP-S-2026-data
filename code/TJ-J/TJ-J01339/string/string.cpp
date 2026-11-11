#include<bits/stdc++.h>
using namespace std;
struct a
{
	int q;
	char w;	
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].q>>a[i].w;
	long long ans=0;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].w!=a[n-i+1].w)
		{
			if(a[i].q>a[n-i+1].q)
			{
				ans=ans+a[n-i+1].q;
				a[n-i+1].w=a[i].w;
				if(a[i].w!=a[n-i].w)
					ans=ans+a[i].q-a[n-i+1].q;
				a[n-i].q=a[n-i].q-a[i].q+a[n-i+1].q;
			}
			else if(a[i].q==a[n-i+1].q)
			{
				ans=ans+a[i].q;
				a[n-i+1].w=a[i].w;
			}
			else
			{
				ans=ans+a[i].q;
				a[i].w=a[n-i+1].w;
				if(a[i+1].w!=a[n-i+1].w)
					ans=ans+a[n-i+1].q-a[i].q;
				a[i+1].q=a[i+1].q+a[i].q-a[n-i+1].q;
			}
		}
	}
	cout<<ans;
	return 0;
} 
