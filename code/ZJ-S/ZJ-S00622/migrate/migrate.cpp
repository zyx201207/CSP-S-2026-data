#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N=2e6+10;
ll c,t,n,d,cd[N],fa[N],sl[N],dq,ans;
void bl(ll wz,ll bs)
{
	if(wz!=dq)
	{
		if(bs<fa[wz])
		{
			if(sl[wz]==2)
			{
				ans--;
			}
			sl[wz]=1;
			fa[wz]=bs;
		}
		else if(bs==fa[wz])
		{
			if(sl[wz]==2)
			{
				ans--;
			}
			if(sl[wz]==1)
			{
				ans++;
			}
			sl[wz]++;
		}
		else
		{
			return;
		}
	}
	for(int i=wz+1;i<=n;i++)
	{
		if(cd[i]-cd[wz]>d)
		{
			return;
		}
		bl(i,bs+1);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>cd[i];
		}
		for(int i=1;i<n;i++)
		{
			memset(fa,0x3f,sizeof fa);
			memset(sl,0,sizeof sl);
			fa[i]=0;
			sl[i]=1;
			dq=i;
			bl(i,0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
