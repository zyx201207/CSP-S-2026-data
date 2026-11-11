#include <bits/stdc++.h>
#define N 1000010
#define ll long long
using namespace std;
int c,t;
int n;
ll d;
ll x[N];
int dis[N];
int pre[N];
ll ans;
inline void Main()
{
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int l=1;l<=n;l++)
	{
		int p1=l,p2=l;
		dis[l]=0,pre[l]=1,pre[l-1]=0;
		for(int i=l+1;i<=n;i++)
		{
			if(x[i]-x[i-1]>d) break;
			while(x[i]-x[p1]>d) p1++;
			dis[i]=dis[p1]+1;
			if(p1>p2)
			{
				p2=p1;
				while(dis[p2+1]==dis[p1]) p2++;
			}
			int sum=pre[p2]-pre[p1-1];
			if(sum>=3) sum=3;
			if(sum==2) ans++;
			pre[i]=pre[i-1]+sum;
		}
	}
	cout<<ans<<'\n';
}
inline void Main1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1) return (void)(cout<<"0\n");
	ll l=d/(x[2]-x[1]);
	if(l<=1) return (void)(cout<<"0\n");
	cout<<max(0ll,n-2*l+1)<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12) while(t--) Main1();
	else while(t--) Main();
	return 0;
}
