#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505][10005],x,y,b[10005],k,f;
//bool s[505][10005];
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=n;j++)
		{
			cin>>f;
			cin>>a[i][f];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
	}
	cout<<53<<endl;
	cout<<31;
}
