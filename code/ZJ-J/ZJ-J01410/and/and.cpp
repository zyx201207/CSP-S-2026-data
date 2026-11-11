#include<bits/stdc++.h>
using namespace std;
int a[200010];
map<int,int>mp;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		mx=max(a[i],mx);
	}
	for(int i=mx;i>=1;i--)
	{
		if(mp[i]>=m)
		{
			cout<<i;
			return 0;
		}
	}
	int ans=mx;
	for(int i=mx;i>=1;i--)
	{
		if(mp[i]!=0)
		{
			ans=ans and i;
			m-=mp[i];
		}
		if(m<0)
		{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}