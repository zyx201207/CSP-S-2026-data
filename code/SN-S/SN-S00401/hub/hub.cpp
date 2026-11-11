#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<int> edge[N];
		for(int i=1;i<n;i++)
		{
			long long u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
	}
	return 0;
}
