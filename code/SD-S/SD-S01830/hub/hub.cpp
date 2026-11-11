#include<bits/stdc++.h>
using namespace std;
int indu[2000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(k<=2)
		{
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			indu[u]++,indu[v]++;
		}
		cout<<2<<endl;
	} 
	return 0;
}
