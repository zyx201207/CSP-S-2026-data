#include <bits/stdc++.h>
using namespace std;
int a[1000000005];
char c[10000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		if(c[i]-'0'==c[1]-'0')
		{
			ans+=a[i];
		}
	}
	cout << ans;
	return 0;
}
