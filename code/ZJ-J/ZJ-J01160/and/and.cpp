#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5+10;


ll n,m,a[MAXN],at[MAXN],ans = 0,vis[MAXN];
char st[MAXN][35];
bool cmp(ll t11,ll t22)
{
	return t11 > t22;
}

ll qpow(ll a,ll b)
{
	ll ans = 1;
	for(;b;b>>=1)
	{
		if(b & 1)
		{
			ans = ans * a;
		}
		a = a * a;
	}
	return ans;
}



int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(st,'0',sizeof(st));
	memset(vis,1,sizeof(vis));
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		at[i] = a[i];
	}
	sort(at+1,at+1+n,cmp);
	ll lth = (ll)log2(at[1])+1;
	for(int i=1;i<=n;i++)
	{
		while(at[i] > 0)
		{
			ll lgtq = (ll)log2(at[i]);
			ll tem = qpow(2,lgtq);
			lgtq ++;
			st[i][lth - lgtq] = '1';
			at[i] -= tem;
		}
	}
	for(int i=0;i<lth;i++)
	{
		ll cnt = 0;
		for(int j=1;j<=n;j++)
		{
			if(st[j][i] == '1' && vis[j])
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans += qpow(2,lth-i-1);
			for(int j=1;j<=n;j++)
			{
				if(st[j][i] == '0')
				{
					vis[j] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
