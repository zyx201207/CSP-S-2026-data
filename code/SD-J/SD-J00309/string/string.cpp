#include<bits/stdc++.h>
using namespace std;
vector<pair<int,char> >a;
int l1=0,l2=0;
long long ans=0;
int main()
{
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	for(int i=0,j=n-1;i<=j;i++,j--)
	{
		pair<int,char>x=a[i],y=a[j];
		if(l1!=0)
		{
			int minn=min(l1,y.first);
			if(a[i-1].second!=y.second)
			{
				ans+=minn;
			}
			y.first-=minn;
			l1-=minn;
		}
		if(l2!=0)
		{
			int minn=min(l2,x.first);
			if(a[i-1].second!=x.second)
			{
				ans+=minn;
			}
			x.first-=minn;
			l1-=minn;
		}
		int minn=min(x.first,y.first);
		if(x.second!=y.second)
		{
		    ans+=minn;
		}
		l1+=(x.first-minn);
		l2+=(y.first-minn);
	}
	cout<<ans;
	return 0;
}
