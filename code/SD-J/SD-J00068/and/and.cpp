#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<int> v,c;
int t,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	v.resize(n+1);
	c.resize(n+1,1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=29;i>=0;i--)
	{
		t=0;
		for(int j=1;j<=n;j++)
		{
			if(!c[j]) continue;
			t+=((v[j]>>i)&1);
		}
		if(t<m) continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++)
		{
			if(!((v[j]>>i)&1)) c[j]=0;
		}
	}
	cout<<ans;
	return 0;
}
