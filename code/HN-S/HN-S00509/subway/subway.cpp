#include<bits/stdc++.h>
using namespace std;


int vis[100005];
int c,n,m,d,q,w[10005]; 

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int t1[k],a1[k];
		for(int j=1;j<=k;j++)	cin>>a1[j]>>t1[j];
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y];
	}	
	/*
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
	*/
	return 0;
}
