#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,c,d,q,j,i,ans,s[500010],w[500010],x,y,o,k[510],f[510][510],h[500010][30],t[500010][30];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
			cin>>x>>y,h[x][++s[x]]=i,t[x][s[x]]=y;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=1e16;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=s[i];j++)
			for(o=1;o<=s[i];o++)
			{
				if(j==o)
				{
					f[h[i][j]][h[i][o]]=f[h[i][o]][h[i][j]]=0;
					break;
				}
				f[h[i][j]][h[i][o]]=f[h[i][o]][h[i][j]]=min(f[h[i][j]][h[i][o]],t[i][j]+t[i][o]);
			}
	}
	for(o=1;o<=n;o++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
	while(q--)
	{
		cin>>x>>y;ans=1e16;
		for(i=1;i<=s[x];i++)
			for(j=1;j<=s[y];j++)
			{
				if(f[h[x][i]][h[y][j]]!=2e9)
					ans=min(ans,f[h[x][i]][h[y][j]]+t[x][i]+t[y][j]);
			}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
