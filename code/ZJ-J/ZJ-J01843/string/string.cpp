#include<bits/stdc++.h>
using namespace std;
int n;
int l[200005];
char c[200005];
long long s[200005],ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>c[i];
		s[i]=s[i-1]+l[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]>=(s[n]-1)/2+1) break;
		long long xl=s[n]-s[i-1],xr=s[n]-s[i]+1;
		if(xl>xr) swap(xl,xr);
		xl=max(xl,(s[n]-1)/2+1);
		int k1=lower_bound(s+1,s+n+1,xl)-s;
		int k2=lower_bound(s+1,s+n+1,xr)-s;
		for(int j=k1;j<=k2;j++) 
		{
			if(c[j]!=c[i]) 
			{
				ans+=max(min(s[j],xr)-max(s[j-1]+1,xl)+1,0LL);
			}
		}
	}
	cout<<ans;
	return 0;
}