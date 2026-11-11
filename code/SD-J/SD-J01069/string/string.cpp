#include<iostream>
#include<cstring>
using namespace std;
long long ans;
struct node
{
	long long x;
	char c;
}a[200005];
int n;
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
	while(l<r)
	{
		if(a[l].c!=a[r].c)
		{
			if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				a[r].c=a[l].c;
				ans+=a[r].x;
				r--;
			}
			else if(a[l].x<a[r].x)
			{
				a[r].x-=a[l].x;
				a[l].c=a[r].c;
				ans+=a[l].x;
				l++;
			}
			else
			{
				ans+=a[l].x;
				a[r].c=a[l].c;
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				r--;
			}
			else if(a[l].x<a[r].x)
			{
				a[r].x-=a[l].x;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
