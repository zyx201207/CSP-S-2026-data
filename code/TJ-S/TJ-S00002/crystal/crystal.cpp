#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000000];
int p=0;
int e=0; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		e++;
	}
	if(e==n){
		for(int i=1;i<=n;i++)
		{
			if(i*(i+1)/2>m)
			{
				cout<<i-1;
				break;
			}
			else
			{
				cout<<n;
			}
		}
	}
	sort(a+1,a+n+1);
	if(m<10000000)
	{
		int z=1;
		for(int i=a[1]+1;i<=a[n];i++)
		{
			if(i>=a[z+1])
			{
				z++;
			}
			int y=z;
			int b=0;
			while(m>b)
			{
				
				b+=i-a[y];
				if(y==0)
				{
					break;
				}
				y--;
				
			}
			p=max(z-y,p);
			
		}
	}
	cout<<p;
	return 0;
}

