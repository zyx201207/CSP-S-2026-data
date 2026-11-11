//orz
#include<iostream>
using namespace std;
long long n,m,sum,a[500010];
void crystal(long long x)
{
	long long b[n+1]={0},sm=1,p=m;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i];
	}
	for(int i=x-1;i>=1;i--)
	{
		if(b[i]==b[x])
		{
			sm++;
		}
		while(p!=0)
		{
			if(b[i]==b[x])
			{
				sm++;
				break;
			}
			b[i]++;
			p--;
		}
		if(m>sum)
		{
			sum=sm;
		}				
	}	 
	return;
}
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for(int i=2;i<=n;i++)
	{
		crystal(i);
	}
	cout<<sum;
	return 0; 
}
