#include<bits/stdc++.h>
using namespace std;
int w[500007];
int k[507];
int t[507][507];
int a[507][507];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j]; 
		} 
	}
	while(q--)
	{
		int g,h;
		cin>>g>>h;
		if(g==h)
		{
			cout<<"0\n";
			return 0;
		} 
		cout<<t[g][h]<<"\n";
	}
	return 0;
}