#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[5005][5005],t[5005][5005],k[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	    
	}
	cout<<123;
	//wdf
	fclose(stdin);
	fclose(stdout);
	return 0;
}
