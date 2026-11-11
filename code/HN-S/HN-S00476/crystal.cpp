#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			cout<<a[i];
		}
	}
	return 0;
}
