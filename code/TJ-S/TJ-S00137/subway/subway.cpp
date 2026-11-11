#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500005],k,x,y,pan;
struct(wry)
{
	int a;
	int t;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>wry.a[i]>>wry.t[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(wry.t[i+1]!=wry.t[i])
		{
			pan=1;
			break;
		}
	}
	if(pan==0)
	{
		ine fen=wry.t[1];
		for(int i=1;i<=p;i++)
		{
			cin>>x>>y;
			cout<<w[x]+w[y]
		}
	}
	return 0;
 } 
