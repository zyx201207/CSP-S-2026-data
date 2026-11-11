#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long x;
	char y;
}a[200005];
long long n,sum,i,j;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i].x>>a[i].y;
	}
	i=1;
	j=n;
	while(i<j)
	{
		if(a[i].y==a[j].y&&a[i].x==a[j].x) continue;
		if(a[i].y==a[j].y)
		{
			if(a[i].x>a[j].x)
			{
				a[i].x-=a[j].x;
				j--;
			}else 
			{
				a[j].x-=a[i].x;
				i++;
			}
		}else
		{
			sum+=min(a[i].x,a[j].x);
			if(a[i].x>a[j].x)
			{
				a[i].x-=a[j].x;
				j--;
			}else 
			{
				a[j].x-=a[i].x;
				i++;
			}
		}
	}
	cout<<sum;
    return 0;
}
