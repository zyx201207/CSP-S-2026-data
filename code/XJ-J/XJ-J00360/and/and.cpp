#include <bits/stdc++.h>
using namespace std;
int m,n,a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("an.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	cout<<a[m];
}