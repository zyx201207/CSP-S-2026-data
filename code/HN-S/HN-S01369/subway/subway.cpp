#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d,w[100005],k[505],a[1005],t[1005],x[100005],y[100005]; 
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int i=1;i<=q;i++)
		{
			cin>>x[i]>>y[i];
		}
	}
	
	return 0; 
}
