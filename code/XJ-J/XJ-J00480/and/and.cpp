#include<bits/stdc++.h>
using namespace std;
long long int n,c[200010],x,m;
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	x=c[n-m+1];
	for(int i=n-m+2;i<=n;i++)
	{
		x=c[i]&x;
	}
	cout<<x;
    return 0;
}
