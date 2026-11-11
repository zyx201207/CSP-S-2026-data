#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
typedef long long ll;
ll a[N];
ll cnt;
queue <ll> q;
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
struct node
{
	ll val;
	ll num;
};
node b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	n=read();
	m=read();
	for (ll i = 1;i <= n;i++)
	{
		a[i]=read();	
	} 
/*	cout << n << " " << m << "\n";
	for (ll i = 1;i <= n;i++)
	{
		cout << a[i] << " ";
	}*/
	/*for (ll i = 1;i <= n;i++)
	{
		if (a[i]!=b[cnt][1]||cnt==0)
		{
			b[++cnt].val=a[i];
			++b[cnt].num;
		}
		else
		{
			++b[cnt].num;
		}
	}*/
	sort(a+1,a+n+1);
	ll sum0=0;
	ll ans=0;
	for (ll i = 1;i <= n;i++)
	{
		while (a[i]*q.size()-sum0>m&&!q.empty())
		{
			sum0-=q.front();
			q.pop();
		}
		ans=max(ans,(ll)(q.size()+1));
		sum0+=a[i];
		q.push(a[i]);
//		cout << q.size() << " " << ans << "\n";
	}
	write(ans);
	return 0;
}

