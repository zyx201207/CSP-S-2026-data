#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m);
	for (int i=0;i<m;i++) cin>>w[i];
	int k;
	vector<ll> a(m),t(m);
	vector<vector<ll> > f(m,vector<ll>(m,inf));
	for (int i=0;i<m;i++)
		f[i][i]=0;
	for (int i=0;i<n;i++)
	{
		cin>>k;
		for (int j=0;j<k;j++) cin>>a[i]>>t[i];
		for (int j=0;j<k;j++)
			for (int p=j+1;p<k;p++)
			{
				f[a[j]-1][a[p]-1]=min(f[a[j]-1][a[p]-1],t[j]+t[p]);
				f[a[p]-1][a[j]-1]=min(f[a[p]-1][a[j]-1],t[j]+t[p]);
			}
	}
	for (int v=0;v<m;v++)
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				f[i][j]=min(f[i][j],f[i][v]+f[v][j]);
	int x,y;
	for (int i=0;i<q;i++)
	{
		cin>>x>>y;
		cout<<f[x-1][y-1]+w[x-1]+w[y-1]<<'\n';
	}
	return 0;
}
