#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,k;
vector<ll>to[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		cout<<k-1<<endl;
	}
	return 0;
 } 
