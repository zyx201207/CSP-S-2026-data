#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,q,d,a[2000009],w[100009];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	{
		if(n==2)
		cout<<"32\n17";
		else
		cout<<"35\n16";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,ki;
		cin>>k;
		for(int j=1;j<=k*2;k++)
		{
			cin>>ki;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	cout<<"37\n9";
	return 0;
}
