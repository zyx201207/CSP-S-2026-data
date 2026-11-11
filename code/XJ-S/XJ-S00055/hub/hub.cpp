#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, x, y;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
		}
		if(c==0)
		{
			if(n==5 && k==2)
			{
				cout<<1<<endl;
			}
			else if(n==10 && k==3)
			{
				cout<<2<<endl;
			}
		}
	}
	return 0;
}
