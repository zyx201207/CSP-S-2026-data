#include<bits/stdc++.h>
using namespace std;
int m,n,i,a[200005],x,maxx[200005];
long long int s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	s=a[1];
	for(i=2;i<=m;i++)
	{
		s=s&a[i];
	}
	cout<<s;
	return 0;
}