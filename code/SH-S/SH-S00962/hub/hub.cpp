#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int> a[2000006];



int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==2)
		{
			cout<<1<<endl;
			break;
		}
		for (int i=1;i<=n;i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
	}
	return 0;
}
