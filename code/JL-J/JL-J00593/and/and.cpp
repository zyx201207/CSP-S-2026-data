#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans=0,anss=-1e9;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	a[0]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		anss=max(anss,a[i]);
	}
	cout<<anss;
	return 0;
}