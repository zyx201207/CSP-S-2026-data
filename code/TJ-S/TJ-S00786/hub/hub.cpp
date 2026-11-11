#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000005],s[100000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int p=1;p<=t;p++)
	{
		cin >> n >> m;
		int b[n],ans=0,wps=0;
		for(int i=1;i<n;i++)
		{
			cin >> a[i] >> s[i];
			b[i]=max(a[i],s[i])-min(a[i],s[i]);
		}
		for(int i=1;i<n;i++)
		{
			if(b[i]==1)
			{
				ans++;
			}
			if(b[i]==2)
			{
				wps++;
			}
		}
		if(ans>wps)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "2" << endl;
		}
	}
	return 0;
}
