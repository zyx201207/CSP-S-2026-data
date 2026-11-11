#include<bits/stdc++.h>
using namespace std;
int a[25][505],minn=1e5,tin[1005];
int c,n,m,d,q,sts,eds;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>tin[i];
	}
	int STa,T;
	for(int i=1;i<=n;i++)
	{
		int z;
		cin>>z;
		for(int j=1;j<=z;j++)
		{
			cin>>STa>>T;
			a[i][STa]=T;
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>sts>>eds;
		if(a[i][sts]!=0&&a[i][eds]!=0)
		{
			cout<<a[i][sts]+a[i][eds]+tin[sts]+tin[eds]<<endl; continue;
		}else
		{
			cout<<"0"<<endl;
		}
		
	}
	return 0;
 } 
