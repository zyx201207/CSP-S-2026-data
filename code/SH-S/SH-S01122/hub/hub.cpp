#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
long long u[1000005];
long long v[1000005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int test=1;test<=t;test++)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
	}
	return 0;
}
