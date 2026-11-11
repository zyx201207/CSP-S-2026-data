#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q,a[5001],p[5001][5001],t[5001][5001],now=1;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>p[i][now]>>t[i][now];
		}`
		now++;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=0;
		cin>>x>>y;
		for(int j=1;j<=now;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(p[k][j]==x) ans+=a[k]+t[k][j];
				if(p[k][j]==y) ans+=a[k]+t[k][j];	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
