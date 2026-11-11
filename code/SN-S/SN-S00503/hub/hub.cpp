//严禹皓 西安交通大学附属中学 SN-S00503 
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			v[i].push_back({u,v});
		}
	}
	return 0;
}
