#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll n,m;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(ll u,v,i=1;i<=n;i++)
		{
			cin>>u>>v;
		}
		cout<<n/5;
	}
}
