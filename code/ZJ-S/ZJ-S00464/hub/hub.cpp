#include<bits/stdc++.h>
using namespace std;
vector<int>e[1000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=1000;i++)e[i].clear();
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
		}
		cout<<e[1].size()<<endl;
	}
	return 0;
}
