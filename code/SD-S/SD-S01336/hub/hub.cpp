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
vector<ll> l[1001000],v[1001000];
ll s[1001000],cnt,vis[1001000],al,ln,viss[1001000];
ll dfs(ll x,ll fa,ll ed)
{
	if(x==ed)return 1;
	s[++cnt]=x;
	for(auto p:l[x])
	{
		if(p==fa)continue;
		if(dfs(p,x,ed))return 1;
	}
	cnt--;
	return 0;
}
ll dfs1(ll x,ll fa)
{
	ll mx=0;
	for(auto p:l[x])
	{
		if(vis[p]||p==fa)continue;
		ll rs=dfs1(p,x);
		if(rs>=ln)al++;
		mx=max(mx,rs+1);
	}
	return mx;
}
ll sol(ll n,ll b)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			cnt=-1;
			dfs(i,0,j);
			for(ll k=1;k<=n;k++)vis[k]=0;
			for(ll k=1;k<=cnt;k++)vis[s[k]]=1;
			vis[i]=vis[j]=1;
			al=2;
			dfs1(i,0);
			dfs1(j,0);
			ll tot=0;
			for(ll k=1;k<=n;k++)v[k].clear(),viss[k]=0;
			for(ll k=1;k<=cnt;k++)
			{
				ll rs=dfs1(s[k],0);
				rs=ln-min(rs,ln);
				ll l=k-rs,r=k+rs;
				if(1<=l&&r<=cnt)
				{
					tot++;
					v[l].push_back(tot);
					v[r].push_back(tot);
				}
			}
			ll sy=b-al;
			if(sy<0)continue;
			if(sy>=cnt||!tot)return 1;
			ll s1=0,s2=cnt+1-sy,nw=0;
			for(ll k=s2;k<=cnt;k++)for(auto p:v[k])
			{
				if(!viss[p])nw++;
				viss[p]++;
			}
			if(nw==tot)return 1;
			while(s2<=cnt)
			{
				s1++;
				for(auto p:v[s1])
				{
					if(!viss[p])nw++;
					viss[p]++;
				}
				for(auto p:v[s2])
				{
					viss[p]--;
					if(!viss[p])nw--;
				}
				s2++;
				if(nw==tot)return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll id=read(),t=read();
	while(t--)
	{
		ll n=read(),b=read();
		for(ll i=1;i<n;i++)
		{
			ll u=read(),v=read();
			l[u].push_back(v);
			l[v].push_back(u);
		}
		ll sl=0,sr=n;
		while(sl<=sr)
		{
			ln=(sl+sr)/2;
			if(sol(n,b))sr=ln-1;
			else sl=ln+1;
		}
		cout<<sl<<"\n";
		for(ll i=1;i<=n;i++)l[i].clear();
	}
	return 0;
}
