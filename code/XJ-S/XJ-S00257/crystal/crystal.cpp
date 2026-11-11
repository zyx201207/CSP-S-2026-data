#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],i,j;
int main()
{
	long long int c,h,s=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	c=a[2]-a[1];
	if(c==0)
	{
		cout<<n;
		return 0;
	}
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	h=int(m*1.0/c);
	i=1;
	while(1)
	{
		s+=i;
		
		if(s>h)
		break;
		if(s==h)
		{
			i+=1;
			break;
		}
		
		i++;
	}
	if(i>=n)
	cout<<n;
	else
	cout<<i;
	return 0;
 } 
