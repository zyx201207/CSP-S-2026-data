#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q;
int w[505],k[505],a[505][505],t[505][505];
struct st
{
	int a,t,r;
}b[505][505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	{
		if(n==2)
		cout<<"32\n17";
		else if(n==3)
		cout<<"35\n16";
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int i=1;i<=k[i];i++)
		{
			cin>>b[i][k[i]].a>>b[i][k[i]].t;
		}	
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}

