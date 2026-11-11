#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll re=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		re=(re<<3)+(re<<1)+c-'0';
		c=getchar();
	}
	return re*f;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
ll n,d;
const int maxn=5005+10;
ll a[maxn];
ll weigh[maxn][maxn];
ll anses[maxn][maxn];
ll work(ll u,ll v)
{
	ll re=0,now=0;
	for(ll i=u+1;i<=v;i++)
	{
		if(a[i]-a[i-1]>d)return -1;
		if(now+a[i]-a[i-1]>d)
		{
			now=a[i]-a[i-1];
			re++;
		}
		else now+=a[i]-a[i-1];
	}
	return re+1;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	//freopen("migrate4.in","r",stdin);
	//freopen("tst.txt","w",stdout);
	
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll c=read();
	ll _=read();
	while(_--)
	{
		n=read();d=read();
		ll tot=0;
		memset(anses,0,sizeof(anses));
		for(ll i=1;i<=n;i++)a[i]=read();
		if(n==1)
		{
			puts("0");
			continue;
		}
		for(ll u=1;u<=n;u++)weigh[u][u]=0,anses[u][u]=1;
		for(ll u=1;u<=n;u++)
		for(ll v=u+1;v<=n;v++)
		{
			ll len=work(u,v);
			if(len==-1)
			{
				weigh[u][v]=1e18;
				anses[u][v]=0;
				continue;
			}
			if(u==v-1)
			{
				anses[u][v]=1;
				weigh[u][v]=1;
				continue;
			}
			weigh[u][v]=len;
			if(len==1)
			{
				anses[u][v]=1;
				continue;
			}
		}
		for(ll u=1;u<=n;u++)
		for(ll v=u+2;v<=n;v++)
		if(weigh[u][v]!=1e18)
		{
			ll ans=0;
			for(ll k=1;k<v;k++)
			if(k!=u)
			{
				ll tu=u,tk=k;
				if(k<u)swap(u,k);
				//cout<<tu<<' '<<v<<' '<<tk<<" : "<<weigh[u][k]<<' '<<weigh[k][v]<<"   "<<weigh[tu][v]<<"    "<<anses[u][k]<<"*"<<anses[k][v]<<'\n';
				if(weigh[u][k]+weigh[k][v]==weigh[tu][v])
				ans+=anses[u][k]*anses[k][v];
				u=tu,k=tk;
			}
			if(anses[u][v]!=1)anses[u][v]=ans;
			//cout<<u<<' '<<v<<' '<<ans<<'\n';
			if(ans==2)
			{
				tot++;
				//cout<<u<<' '<<v<<' '<<len<<'\n';
			}
		}
		write(tot);putchar('\n');
	}
	return 0;
}
/*

dont press F11

seek if need long long

ensure function return

ensure file & extra output




0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6




*/
