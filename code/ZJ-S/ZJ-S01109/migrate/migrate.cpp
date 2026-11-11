#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e6+10;
ll c,t,n,d,a[N],ml[N],sum[N],ans;
void dfs(ll now,ll bs)
{
  if(ml[now]>bs) return;
  if(ml[now]==bs) sum[now]++;
  for(ll i=now+1;i<=n;i++)
  {
  	if(a[i]-a[now]>d) break;
  	dfs(i,bs+1);
  }
}
int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  AC;
  cin>>c>>t;
  while(t--)
  {
  	ans=0;
  	cin>>n>>d;
  	for(ll i=1;i<=n;i++) cin>>a[i];
  	for(ll i=1;i<n;i++)
  	{
  	  ll ls=i;
  	  ml[ls]=0;
  	  for(ll j=i+1;j<=n;j++)
  	  {
  	  	if(a[j]-a[j-1]>d) break;
  	  	if(a[j]-a[ls]>d) ls=j-1;
		ml[j]=ml[ls]+1;
		sum[j]=0;
	  }
	  dfs(i,0);
	  for(ll j=i+1;j<=n;j++)
	  {
	    if(a[j]-a[j-1]>d) break;
	    if(sum[j]==2) ans++;
	  }
	}
	cout<<ans<<"\n";
  }
  return 0;
}
