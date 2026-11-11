#include <iostream>
using namespace std;
int a[200005];
int c,maxn=-1;
int n,m;
int f(int x)
{
	for(int i=x;i<=m;i++)
	{
		return a[i]&a[i+1];	
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		maxn=max(f(i),maxn);
	}
	cout<<maxn;
	return 0;
}