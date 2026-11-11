#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int cnt[300010];
int ans[300010];
stack<int> st;
int n,m;
void solveg()
{
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cnt[i]=cnt[i]+cnt[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag)
	{
		solveg();
		return 0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
	return 0;
}
