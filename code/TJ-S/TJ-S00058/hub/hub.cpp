#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
int b[1000005];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		for(int i = 1;i < n;i++)
		{
			cin >> a[i] >> b[i];
		} 
	}
	return 0;
}
