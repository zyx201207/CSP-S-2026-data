#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	c=(c==0) ? 1 : c;
	for(long long x=0;x<c;x++)
	{
		for(long long s=0;s<t;s++)
		{
			long long n,k;
			cin>>n>>k;
			for(long long i=0;i<n-1;i++)
			{
				long long u,v;
				cin>>u>>v;
			}
			cout<<k-1<<endl;
		}
	}
	return 0;
}
