#include<bits/stdc++.h>
using namespace std;
long long r,l;
const int N=200005;
long long a[N];
char c[N];
long long ans,sum,f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[l];
	}
	if(sum%2==1)
	{
		long long temp=sum/2+1;
		for(int i=1;i<=n;i++)
		{
			if(temp=a[l])
			temp=a[l];
		}
	}
	int l=0,r=n;
	long long ef=a[l],g=a[r];
	while(l<=r)
	{
		if(ef<g)
		{
			if(c[l]<=c[r])
			ans+=f;
			else
			{
			i++;
			e=a[l];	
			}
		else if(e==g)
		{
			if(c[l]!=c[r])
			ans+=e;
			i++;
			r--;
			k1=a[l];
		}
		if(k1=k2)
		{
			if(c[l]!=c[r])
			ans-=k2;
			i--;
			k2=a[r];
		}
	}
	return 0;
}
