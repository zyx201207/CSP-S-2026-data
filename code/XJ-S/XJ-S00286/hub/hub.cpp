#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==1)
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
			}
			if(k==n)
			{
				cout<<0<<endl;
				continue;
			}
			cout<<1<<endl;
		}
	}
	return 0;
}
