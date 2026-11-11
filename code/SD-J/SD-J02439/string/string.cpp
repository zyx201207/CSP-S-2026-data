#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,k;
struct Node{
	char zm;
	long long gs;
}a[N];
int main()
{
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].gs>>a[i].zm;
	}
	long long ys=0,z=1,y=n;
	while(z<=y)
	{
		if(a[z].zm==a[y].zm)
		{
			if(a[z].gs==a[y].gs)
			{
				z++;y--;
			}
			else
			{
				if(a[z].gs>a[y].gs)
				{
					a[z].gs-=a[y].gs;
					y--;
				}
				else
				{
					a[y].gs-=a[z].gs;
					z++;
				}
			}
		}
		else
		{
			if(a[z].gs==a[y].gs)
			{
				k+=a[z].gs;
				z++;y--;
			}
			else
			{
				if(a[z].gs>a[y].gs)
				{
					a[z].gs-=a[y].gs;
					k+=a[y].gs;
					y--;
				}
				else
				{
					a[y].gs-=a[z].gs;
					k+=a[z].gs;
					z++;
				}
			}
		}
	}
	cout<<k;
	return 0;
}

