#include<bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
const ll N=5e5+1010;
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
ll c,n,m,d,q,f[510][510],a,tim,w[N],k,x,y,ans;
struct node
{
	ll tim,id;
};
vector<node> e[N];
vector<node> p[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			f[i][j]=2e17;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		k=read();
		for(ll j=1;j<=k;j++)
		{
			a=read();
			tim=read();
			for(node&v:p[a]) if(tim+v.tim<f[v.id][i]) f[i][v.id]=f[v.id][i]=tim+v.tim;
			p[a].push_back({tim,i});
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) if(f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[j][i]=f[i][k]+f[k][j];
		}
	}
	while(q--)
	{
		x=read();y=read();
		ans=2e18;
		for(node&v:p[x])
		{
			for(node&u:p[y])
			{
				ans=min(ans,f[v.id][u.id]+w[x]+w[y]+v.tim+u.tim);
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}