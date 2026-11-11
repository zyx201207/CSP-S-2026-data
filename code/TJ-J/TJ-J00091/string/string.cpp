#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],x=-1,sum;
string c,d;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
		cin>>c[i];
		for(int j=x+1;j<=x+a[i];j++)
		{
			d[j]=c[i];
		}
		x=x+a[i];
	}
	for(int i=0;i<=x/2;i++)
	{
		if(d[i]!=d[x-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
