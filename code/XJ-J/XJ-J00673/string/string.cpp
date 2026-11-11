#include<bits/stdc++.h>
using namespace std;
long long int a[200005],n,ans,f=1,l,r,i,z;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		z+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])
		f=0;
	}
	if(f==1)
	{
		l=1;
		r=n;
		while(l>=r)
		{
			if(c[l]!=c[r])
			ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
}