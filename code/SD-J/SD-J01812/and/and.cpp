#include <bits/stdc++.h>
using namespace std;
int a[10003],c[10000],s[10000],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
	if(a[i]%2==a[i+1]%2)
	cout<<a[i];
	}
	return 0;
 } 
