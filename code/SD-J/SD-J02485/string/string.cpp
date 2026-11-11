#include <iostream>
#include <cstdio> 
using namespace std;
const int N=1e5*2;
long long a[N+5];char c[N+5];
int top=0;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;long long sum=0;
	cin>>n;
	while(n--)
	{
		int m;char x;
		cin>>m>>x;
		if(c[top]==x)
		a[top]+=m;
		else
		{
			top++;
			c[top]=x;a[top]=m;
		}
	}
	/*for(int i=1;i<=top;i++)
	cout<<a[]*/
	int l=1,r=top;
	while(l<r)// shuang zhi zhen
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				sum+=a[r];
				r--;
			}
			else
			{
				if(a[l]<a[r])
			{
				a[r]-=a[l];
				sum+=a[l];
				l++;
			}
			else
			if(a[l]==a[r])
			{
				sum+=a[l];
				l++;
				r--;
			}
			}
			
		}
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				
				if(a[l]<a[r])
			    {
				a[r]-=a[l];
				l++;
			    }
			    else
			    if(a[l]==a[r])
			    {
				l++;
				r--;
			    }
				
			 } 
			
		}
	}
	cout<<sum;
	return 0;
}
