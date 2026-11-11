#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
long long a[N+5];
char c[N+5];
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long l=1,r=n,ans=0;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else
			{
				ans+=a[l];
				l++;
				r--;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
