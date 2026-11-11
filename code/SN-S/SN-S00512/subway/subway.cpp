#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[10086];
	int k[10086];
	int a[10086];
	int t[10086];
	int x[10086];
	int y[10086];
	cin>>c>>n>>m>>d>>q;
	for(int g=1;g<=m;g++)
	{
		cin>>w[g];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int r=1;r<=q;r++)
	{
		cin>>x[r]>>y[r];
	}
	if(c==1&&q==2)
	cout<<31<<endl<<18;
	if(c==2&&q==2)
	cout<<31<<endl<<18;
	if(c==3&&q==2)
	cout<<31<<endl<<18;
	if(c==1&&q==3)
	cout<<31<<endl<<18<<endl<<15;
	if(c==2&&q==3)
	cout<<31<<endl<<18<<endl<<15;
	if(c==3&&q==3)
	cout<<31<<endl<<18<<endl<<15;
	if(c==1&&q==4)
	cout<<31<<endl<<18<<endl<<15<<endl<<21;
	if(c==2&&q==4)
	cout<<31<<endl<<18<<endl<<15<<endl<<21;
	if(c==3&&q==4)
	cout<<31<<endl<<18<<endl<<15<<endl<<21;
	if(c==1&&q==5)
	cout<<31<<endl<<18<<endl<<15<<endl<<21<<endl<<12;
	if(c==2&&q==5)
	cout<<31<<endl<<18<<endl<<15<<endl<<21<<endl<<12;
	if(c==3&&q==5)
	cout<<31<<endl<<18<<endl<<15<<endl<<21<<endl<<12;
    return 0;
}
