#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	  cin>>a[i]>>c[i];
	long long l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			long long t=min(a[l],a[r]);
			a[l]-=t;
			a[r]-=t;
		}
		else 
		{
			long long k=min(a[l],a[r]);
			a[l]-=k;
			a[r]-=k;
			ans+=k;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
