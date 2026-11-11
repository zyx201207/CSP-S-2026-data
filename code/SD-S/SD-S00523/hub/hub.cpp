#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v;
		int kk=(n-1)>>1;
		for(int i=1;i<=n;i++)
		{
			if(k>=n/(2*i))
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}
