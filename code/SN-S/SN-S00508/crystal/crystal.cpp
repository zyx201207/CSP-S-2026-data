//by : xt66666
//lihaoyang
//TYZ
//SN-S00508
//luogu uid : 去年就忘了，今年还是没记住
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mid ((l+r)>>1)
#define lc t[p].ls
#define rc t[p].rs
#define pb push_back
#define fir first
#define sec second
ll n,m;
ll a[500010];
ll s[500010];
//好诶T1纯乐有救
 

//
void solve()
{
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
//	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ll now=0;
		for(int j=1<<22;j;j>>=1)if(now+j<=i&&a[i]*(now+j)-(s[i]-s[i-(now+j)])<=m)now+=j;
		ans=max(ans,now);
	}
	cout<<ans;	
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ll T=1;
	while(T--)solve();
	return 0;
}
