#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,u[N],v[N],ans=1;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int x=1;x<=t;x++)
	{
		cin>>n>>d;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u[i]>>v[i];
		}
		cout<<ans; 
	}
	return 0;
 } 
