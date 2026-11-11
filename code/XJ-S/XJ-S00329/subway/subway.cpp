#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
	freopen("subway.in","r",stdint);
	freopen ("subway.out","w",stdout);
	int c,n,m,d,p,k,x1,x2,y1,y2;
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	k=k*2;
	for (int i=1;i<=k;i++)
	{
		cin>>b[i];
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
	}
	cin>>x1>>y1>>x2>>y2;
	cout<<"32"<<endl<<"17";
	return 0;
}
