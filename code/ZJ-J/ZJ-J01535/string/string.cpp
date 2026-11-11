#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	long long num;
	char id;
}a[N];
long long ans,sum[N];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].id;
		sum[i]=sum[i-1]+a[i].num;
	}
	long long l=1,r=sum[n],x=1,y=n;
	while(l<r)
	{
		if (a[x].id!=a[y].id)
		{
			int i=sum[x]-l+1,j=r-sum[y-1];
			if (i>j)
			{
				ans+=j;
				r=sum[y-1];
				l+=j;
				y--;
			}
			else 
			{
				ans+=i;
				l=sum[x]+1;
				r-=i;
				x++;
			}
		}
		else
		{
			int i=sum[x]-l+1,j=r-sum[y-1];
			if (i>j)
			{
				r=sum[y-1];
				l+=j;
				y--;
			}
			else 
			{
				l=sum[x]+1;
				r-=i;
				x++;
			}
		}
	}
	cout<<ans;
	return 0;
}
