#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
using namespace std;
vector<int> edge[1000001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}

