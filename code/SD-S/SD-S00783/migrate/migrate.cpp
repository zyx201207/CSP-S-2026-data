#include<bits/stdc++.h>
#define fi first
#define se second
#define inf 2e18
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e6+10;
ll c,t,n,d;
ll a[N],dep[N],sum[N];
ll ans;
int f(int id)
{
	int ans=0;
	dep[id]=0;sum[id]=1;
	for(int i=id+1;i<=n;i++)
	{
	  int x=lower_bound(a+id,a+n+1,a[i]-d)-a,y;
	  dep[i]=dep[x]+1;
	  y=upper_bound(dep+id,dep+i+1,dep[x])-dep;
	  if(y-x<=2){
	  	for(int j=x;j<=y-1;j++)
	  	  sum[i]+=sum[j];
	  }
//	  cout<<sum[i]<<"\n";
	  if(sum[i]!=1&&sum[i]!=2)  sum[i]=inf;
	  if(sum[i]==2) ans++;
	}
	for(int i=1;i<=n;i++)  dep[i]=sum[i]=0;
	return ans;
}
void g()
{
	ll ans=0;
	dep[1]=0;sum[1]=1;
	for(int i=2;i<=n;i++)
	{
	  int x=lower_bound(a+1,a+n+1,a[i]-d)-a,y;
	  dep[i]=dep[x]+1;
	  y=upper_bound(dep+1,dep+i+1,dep[x])-dep;
	  if(y-x<=2){
	  	for(int j=x;j<=y-1;j++)
	  	  sum[i]+=sum[j];
	  }
//	  cout<<sum[i]<<"\n";
	  if(sum[i]!=1&&sum[i]!=2)  sum[i]=inf;
	  if(sum[i]==2) ans+=(n-i+1);
	}
	for(int i=1;i<=n;i++)  dep[i]=sum[i]=0;
	cout<<ans<<"\n";
} 
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)  cin>>a[i];
	if(c==11||c==12)
	{
	  g();
	  return;
	}
	if(c==13||c==14)
	{
	  cout<<"0\n";
	  return;
	}
	for(int i=1;i<=n;i++)  ans+=f(i);
	cout<<ans<<"\n";
	ans=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)  solve(); 
	return 0;
}

