#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct point{
	long long x;
	char c;
}a[101010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l!=r)
	{
		if(a[l].x>a[r].x)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[r].x;
			}
			a[l].x-=a[r].x;
			r--;
		}
		else if(a[l].x<a[r].x)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[l].x;
			}
			a[r].x-=a[l].x;
			l++;
		}
		else if(a[l].x==a[r].x)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[l].x;
			}
			l++;
			r--;
		}	
	}
	cout<<ans;
	return 0;
}