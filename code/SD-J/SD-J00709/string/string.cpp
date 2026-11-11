#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;

struct Node{
	int x;
	char c;
}a[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].x==a[r].x)
			{
				l++,r--;
			}
			else if(a[l].x<a[r].x)
			{
				a[r].x-=a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				r--;
			}
		}
		else
		{
			if(a[l].x==a[r].x)
			{
				ans+=a[l].x;
				l++,r--;
			}
			else if(a[l].x<a[r].x)
			{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x)
			{
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
