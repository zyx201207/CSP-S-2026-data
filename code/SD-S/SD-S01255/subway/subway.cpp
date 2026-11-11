#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
const int INF=0x3f3f3f3f;
typedef long long ll;
ll sta[N];
ll a[N][N];
ll roa[N][3]; 
inline ll read()
{
	ll o=0,p=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
		{
			p=-1;
		}
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		o=o*10+c-'0';
		c=getchar();
	}
	return o*p;
}
inline void write(ll d)
{
	if (d<0)
	{
		putchar('-');
		d=-d;
	}
	if (d>9)
	{
		write(d/10);
		d=d%10;
	}
	putchar(d+'0');
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for (ll i = 1;i <= m;i++)
	{
		sta[i]=read();
	}
	if (c>=7&&c<=11)
	{
		
	}
	for (ll i = 0;i <= m;i++)
	{
		for (ll j = 0;j <= m;j++)
		{
			a[i][j]=INF;
		}
	}
	for (ll i = 1;i <= n;i++)
	{
		ll k;
		k=read();
		for (ll j = 1;j <= k;j++)
		{
			roa[j][1]=read();
			roa[j][2]=read();
		}
		for (ll l = 1;l <= k;l++)
		{
			for (ll r = 1;r <= k;r++)
			{
				a[roa[l][1]][roa[r][1]]=min(a[roa[l][1]][roa[r][1]],roa[l][2]+roa[r][2]);
				a[roa[r][1]][roa[l][1]]=min(a[roa[r][1]][roa[l][1]],roa[l][2]+roa[r][2]);
			}
		}
	}
/*	for (ll i = 1;i <= m;i++)
	{
		for (ll j = 1;j <= m;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (ll u = 1;u <= m;u++)
	{
		for (ll l = 1;l <= m;l++)
		{
			for (ll mi = 1;mi <= m;mi++)
			{
				if (a[l][mi]==INF||l==mi) continue;
				for (ll r = 1;r <= m;r++)
				{
					if (a[mi][r]==INF||mi==r||l==r) continue;
					a[l][r]=min(a[l][r],a[l][mi]+a[mi][r]); 
				}
			}
		}
	}
/*	for (ll i = 1;i <= m;i++)
	{
		for (ll j = 1;j <= m;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}*/
	while (q--)
	{
		ll x1,x2;
		x1=read();
		x2=read();
		write(a[x1][x2]+sta[x1]+sta[x2]);
		printf("\n"); 
	//	printf("%lld\n",a[x1][x2]+sta[x1]+sta[x2]);
	}
	return 0;
}

