#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
struct node{
	long long x;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	long long i=1,k=n;
	while(i<k)
	{
		if(a[i].c==a[k].c) 
		{
			if(a[i].x>a[k].x)
			{
				a[i].x-=a[k].x;
				k--;
			}
			else if(a[i].x<a[k].x)
			{
				a[k].x-=a[i].x;
				i++;
			}
			else if(a[i].x==a[k].x)
			{
				i++,k--;
			}
		}
		else
		{
			if(a[i].x>a[k].x)
			{
				a[i].x-=a[k].x;
				sum+=a[k].x;
				k--;  
			}
			else if(a[i].x<a[k].x)
			{
				a[k].x-=a[i].x;
				sum+=a[i].x;
				i++;
			}
			else if(a[i].x==a[k].x)
			{
				sum+=a[i].x;
				i++,k--;
			}
		}
	}
	cout<<sum;
	return 0;	
}
