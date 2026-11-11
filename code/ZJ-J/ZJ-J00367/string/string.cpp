#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	long long v;
	char b;
}a[200010];
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].b;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(a[l].v!=a[r].v)
		{
			if(a[l].b!=a[r].b)
			{
				if(a[l].v>a[r].v)
				{
					
					a[l].v-=a[r].v;
					ans+=a[r].v;
					r--;
				}
				else
				{
					
					a[r].v-=a[l].v;
					ans+=a[l].v;
					l++;
				}
			}
			else
			{
				if(a[l].v>a[r].v)
				{
					
					a[l].v-=a[r].v;
					r--;
				}
				else
				{
					
					a[r].v-=a[l].v;
					l++;
				}
			}
		}
		else
		{
			
			if(a[l].b!=a[r].b)
			{
				ans+=a[l].v;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
    