#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	longlong n,m;
	cin>>n>>m;
	longlong a[n];
	for(longlong i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	longlong r=a[0];
	for(longlong i=0;i<m;i++)
	{
		r&=a[i];
	}
	cout<<r;
	return 0;
}
