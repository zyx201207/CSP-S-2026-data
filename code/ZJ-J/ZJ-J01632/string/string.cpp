#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
long long ans;
char c[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]<a[r])
			{
				ans+=a[l];
				cout<<ans<<endl;
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				ans+=a[r];
				cout<<ans<<endl;
				a[l]-=a[r];
				r--;
			}
			else
			{
				ans+=a[l];
				cout<<ans<<endl;
				l++;
				r--;
			}
		}
		else
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}