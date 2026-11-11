#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],kk,a[1000005],x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(m==0) {cout<<0;return 0;}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if((n==0)||(d==0)) {cout<<0;return 0;}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		kk=2*k[i];
		for(int j=1;j<=kk;j++)
		{
			cin>>a[i];
		}
	}
	if(q==0) {cout<<0;return 0;}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
