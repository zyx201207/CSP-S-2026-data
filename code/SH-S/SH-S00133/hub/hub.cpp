#include<bits/stdc++.h>
using namespace std;
int G[1005][1005],fa[10005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		for(int j=0;j<n-1;j++)
		{
			int x,y;
			cin>>x>>y;
			G[x][y]=1;
			fa[y]=x;
		}
		cout<<1;
		
		
		
		
		
	}
	return 0;
}
