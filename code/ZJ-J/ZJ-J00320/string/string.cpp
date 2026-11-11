#include<bits/stdc++.h>
using namespace std;

long long a[200000+10];
char c[200000+10];
int main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l<r)
	{
		int x=min(a[l],a[r]);
		if(c[l]!=c[r])
		{
			ans+=x;
		}
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0)
		{
			l++;
		}
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
