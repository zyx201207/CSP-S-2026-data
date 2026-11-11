#include<bits/stdc++.h>
using namespace std;
long long n,p,l;
long long a[300005];
char c[300005],d[300005];
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		p+=a[i]; 
	}
	long long t=1;
	for(int i=1;i<=p;i++)
	{
		if(a[t]==0)
		{
			t++;
		}
		d[i]=c[t];
		a[t]--; 
	}
	for(int i=1;i<=p/2;i++)
	{
		if(d[i]!=d[p+1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}


