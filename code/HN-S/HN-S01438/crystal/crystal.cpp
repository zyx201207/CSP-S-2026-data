#include<bits/stdc++.h> 
#include<cstdio>
int n,m,ans,a[100005];
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=m;j++)
		{
		a[i]=a[i]+j;
		if(a[i]<=2)
		ans++;
}}
	cout<<ans;
	return 0;
}
