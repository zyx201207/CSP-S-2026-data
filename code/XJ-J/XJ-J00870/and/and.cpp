#include<bits/stdc++.h>
using namespace std;
long long n,m,x,p,a[500005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[1];
	return 0;
}