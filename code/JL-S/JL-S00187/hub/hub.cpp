#include<bits/stdc++.h>
using namespace std;
long long u[100005],v[100005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,k;
		cin>>n>>k;
		for(int j=1;j<=n-1;j++)
		{
			cin>>u[j]>>v[j];
		}
	}
	return 0;
}
