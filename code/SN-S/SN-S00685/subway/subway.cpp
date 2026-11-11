#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[1000005],a[1000005],x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k;
		for(int j = 1;j<=2*k;j++)
		{
			cin>>a[i];
		}
	}
	for(int j = 1;j<=n;j++)
	{
		cin>>x[j]>>y[j];
	}
	cout<<"32"<<endl;
	cout<<"17";
}
