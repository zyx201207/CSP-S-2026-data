#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll sum=0,l=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')l=-1;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*l;
}
ll c[500100],dis[510][510],s[500100][22],t[500100][22],sz[500100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll id=read(),n=read(),m=read(),a=read(),b=read();
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=m;i++)c[i]=read();
	for(ll i=1;i<=n;i++)
	{
		dis[i][i]=0;
		ll l=read();
		for(ll j=1;j<=l;j++)
		{
			ll x=read(),y=read();
			sz[x]++;
			s[x][sz[x]]=i;
			t[x][sz[x]]=y;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=sz[i];j++)
		{
			for(ll k=j+1;k<=sz[i];k++)
			{
				ll x=s[i][j],y=s[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],t[i][j]+t[i][k]);
			}
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ll i=1;i<=b;i++)
	{
		ll x=read(),y=read();
		ll ans=dis[0][0];
		for(ll j=1;j<=sz[x];j++)
		{
			for(ll k=1;k<=sz[y];k++)
			{
				ans=min(ans,t[x][j]+t[y][k]+dis[s[x][j]][s[y][k]]);
			}
		}
		cout<<ans+c[x]+c[y]<<"\n";
	}
	return 0;
}
