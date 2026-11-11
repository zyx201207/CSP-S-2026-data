#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		int t;
		cin>>t;
		for(int i=1;i<=t;++i)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
	}
	for(int i=1;i<=q;++i)
	{
		int l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]+a[l]+a[r]<<endl;
	}
	return 0;
}
