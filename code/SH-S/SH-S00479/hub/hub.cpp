#include<bits/stdc++.h>
#define N 100005
using namespace std;
//T4Ï¹Ð´µÄ0 
int c,t,n,k,u,v;
vector<int>edge[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cout<<(n+k-1)/k-1<<'\n';
	}
	return 0;
}
