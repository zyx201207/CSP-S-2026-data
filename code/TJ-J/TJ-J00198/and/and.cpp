#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=a[i]-'0';
	}
	int maxx=0;
	for(int i=0;i<n;i++)
	{
		int po=b[i]&&b[i+1];
		maxx=max(po,maxx);
	}
	cout<<maxx;
	
	
	return 0;
}
