#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans;
vector<int>v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	if(n==m)
	{
		ans=v[0];
		for(int i=1;i<v.size()-1;i++)
		{
			ans&=v[i];
		}
		cout<<ans;
		return 0;
	}
	sort(v.rbegin(),v.rend());
	ans=v[0];
	for(int i=1;i<=m-1;i++)
	{
		ans&=v[i];
	}
	cout<<ans;
	return 0;
} 
