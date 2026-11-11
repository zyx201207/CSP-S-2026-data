#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,t,x,y,z,ans;
ll a[500005];
ll f[23][500005];
ll g[23][500005];
ll h[500005];
ll dp[505][505];
ll A,B;
char X;
ll read()
{
	A=0;B=0;
	for(;;)
	{
		X=getchar();
		if(X=='-')
		{
			B=1;
			X=getchar();
			break;
		}
		if(X>='0'&&X<='9')break;
	}
	for(;;)
	{
		A=(A<<3)+(A<<1)+X-'0';
		X=getchar();
		if(X<'0'||X>'9')break;
	}
	if(B==1)A=-A;
	return A;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	x=read();n=read();m=read();y=read();k=read();
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)dp[i][j]=1e18;
	for(ll i=1;i<=n;i++)dp[i][i]=0;
	for(ll i=1;i<=m;i++)a[i]=read();
	for(ll i=1;i<=n;i++)
	{
		t=read();
		for(ll j=1;j<=t;j++)
		{
			x=read();y=read();
			h[x]++;f[h[x]][x]=i;g[h[x]][x]=y;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=h[i];j++)
		{
			for(ll l=j+1;l<=h[i];l++)
			{
				x=f[j][i];y=f[l][i];z=g[j][i]+g[l][i];
				if(dp[x][y]>z){dp[x][y]=z;dp[y][x]=z;}
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll l=1;l<=n;l++)
			{
				z=dp[j][i]+dp[i][l];
				if(dp[j][l]>z)dp[j][l]=z;
			}
		}
	}
	for(ll i=1;i<=k;i++)
	{
		ans=1e18;
		x=read();y=read();
		for(ll j=1;j<=h[x];j++)
		{
			for(ll l=1;l<=h[y];l++)
			{
				z=g[j][x]+g[l][y]+dp[f[j][x]][f[l][y]];
				if(ans>z)ans=z;
			}
		}
		ans+=a[x];ans+=a[y];
		printf("%lld\n",ans);
	}
	return 0;
}
