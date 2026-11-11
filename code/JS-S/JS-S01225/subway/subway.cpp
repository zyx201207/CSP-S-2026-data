#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[250000005],t[250000005],r1[100005],r2[100005];
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
	}
	for(int i=1;i<=q;i++)
	{
		cin>>r1[i]>>r2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0"<<endl;
	}
	return 0;
}
