#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5000005];
char c[5000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
		for(int i=1;i<=n;i++)
		{
			ans+=a[i];
		}
		cout<<ans/2;
	return 0;
}
