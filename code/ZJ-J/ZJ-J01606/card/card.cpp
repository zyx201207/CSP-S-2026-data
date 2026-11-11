#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
 }
