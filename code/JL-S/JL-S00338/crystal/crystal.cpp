#include<bits/stdc++.h>
using namespace std;
#define N 1000000
long long  x[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,q=0,sum=0,cnt=0;
	cin>>n>>m;
	if(m==0){
		cout<<0<<endl;
		return 0;
	}
	for(long long  i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	for(long long  i=0;i<n;i++)
	{
		if(x[i]==x[i+1])
		{
			q=x[i];
		}
	}
	if(q==0)
	{
		for(long long  i=0;i<n;i++)
		{
			sum+=x[i];
		}
		sum/=n;
		for(long long  i=0;i<n;i++)
		{
			if(x[i]<=sum)
			{
				long long  z,y;
				z=sum;
				y=x[i];
				x[i]+=(sum-x[i]);
				m=m-(z-y);
				cnt++;
			}
		}
		cout<<cnt<<endl;
		return 0;
	}
	else
	{
		for(long long i=0;i<n;i++)
		{
			if(x[i]<=q)
			{
				long long  g,h;
				g=q;
				h=x[i];
				x[i]+=(g-x[i]);
				m=m-(g-h);
				cnt++;
			}
		}
		cout<<cnt<<endl;
		return 0;
	}
	return 0;
}
/*
  5 5
  1 2 4 8 9
 */
