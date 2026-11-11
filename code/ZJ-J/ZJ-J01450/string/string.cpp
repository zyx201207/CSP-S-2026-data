#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	vector<pair<int,char> > a;
	long long c=0;
	cin>>n;
	a.push_back({0,'0'});
	for (int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		c+=x;
		a.push_back({x,y});
	}
	long long t=c/2,ans=0,r1=0,r2=0;
	int l=1,r=n;
	while (l<r)
	{
		int x1=a[l].first-r1,x2=a[r].first-r2;
		char y1=a[l].second,y2=a[r].second;
		if (x1>=x2)
		{
			if (y1!=y2)
			{
				ans+=x2;
			}
			r1+=x2;
			r2=0;
			r--;
		}
		else
		{
			if (y1!=y2)
			{
				ans+=x1;
			}
			r1=0;
			r2+=x1;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
