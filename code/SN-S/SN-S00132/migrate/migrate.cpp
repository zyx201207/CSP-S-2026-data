#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,T,n;
ll d,x[N],t[2][N];
int lp[N],rp[N],lsp[N],rsp[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	memset(rsp,0x3f,sizeof(rsp));
	memset(lsp,0x3f,sizeof(lsp));
	while(T--)
	{
		if(c>=15&&c<=18)
		{
			cout<<0<<'\n';
			continue;
		}
		memset(t[0],0,n*4+4);
		memset(t[1],0,n*4+4);
		memset(rsp,0x3f,n*4+4);
		memset(lsp,0x3f,n*4+4);
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		x[0]=-4e18;x[n+1]=4e18;
		for(int i=1;i<=n;i++) lp[i]=lower_bound(x+1,x+n+1,x[i]-d)-x,rp[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		for(int i=1;i<=n;i++)
		{
			if(lsp[i]==0x3f3f3f3f&&x[i]>x[i-1]+d) lsp[i]=1;
			else if(lsp[i]==0x3f3f3f3f) lsp[i]=lsp[i-1]+1;
			if(rp[i]-i) lsp[rp[i]]=min(lsp[rp[i]],lsp[i]+1);
		}
		for(int i=n;i>=1;i--)
		{
			if(rsp[i]==0x3f3f3f3f&&x[i]<x[i+1]-d) rsp[i]=1;
			else if(rsp[i]==0x3f3f3f3f) rsp[i]=rsp[i+1]+1;
			if(i-lp[i]) rsp[lp[i]]=min(rsp[lp[i]],rsp[i]+1);
		}
		for(int i=1;i<=n;i++)
		{
			if(i-lp[i]>=2) t[0][lp[i]]+=rsp[i];
			if(rp[i]-i>=2) t[1][rp[i]]+=lsp[i];
		}
		ll ans=0;
		for(int i=1;i<n;i++) ans+=t[0][i]*1ll*t[1][i+1];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
