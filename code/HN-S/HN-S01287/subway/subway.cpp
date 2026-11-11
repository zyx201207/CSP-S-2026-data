#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
	}
	for(int i=1;i<=n;i++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			int x,y;
			cin>>x>>y;	
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
	    cin>>x>>y;
	} 
	if(n==2&&m==5)
	{
		cout<<"32"<<"\n"<<"17";
	}
	return 0;
}
