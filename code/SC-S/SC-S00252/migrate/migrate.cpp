#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int c;
const int maxn=1e6+9;
const int INF=3e18;
int n,a[maxn];
int d;
int calc(int st,int ed)
{
	int now=st;
	int res=0;
	while(now<ed)
	{
		int nt=lower_bound(a+1,a+n+1,a[now]+d)-a;
		if(a[nt]!=a[now]+d) nt--;
		if(nt>ed) nt=ed;
		if(nt==now) return 0;
		int lt=lower_bound(a+1,a+n+1,a[nt]-d)-a;
		if(lt<st) lt=st;
	    //if(st==2&&ed==4) cout<<now<<' '<<nt<<' '<<lt<<'\n';
		res+=now-lt;
		now=nt;
	}
	return res;
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=INF;
	a[0]=-INF;
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		for(int j=i+2;j<=n;j++)
		{
			if(calc(i,j)==1) 
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}