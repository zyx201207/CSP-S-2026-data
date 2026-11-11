#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N=5e5+5,OOO=1e18;
ll n,m,a[N],b[2][25],ans=0;
bool tpa=true,tpb=true,yman=false;
bool cmp(ll x,ll y)
{
	return x<y;
}
void dfs(ll step,ll k)
{
	if(yman)
		return ;
	if(k<0)
		return ;
	if(step>m)
		return ;
		
	for(int i=0;i<=1;i++)
		for(int j=0;j<=24;j++)
			b[i][j]=0;
	ll mmax=0; 
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)
		{
			b[1][a[i]]++;
			mmax=max(mmax,b[1][a[i]]);
		}
		else
		{
			b[0][abs(a[i])]++;
			mmax=max(mmax,b[0][abs(a[i])]);
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<" ";
//	cout<<"   "<<k<<'\n';
	ans=max(ans,mmax);
	if(ans==n)
		yman=1;
	for(int i=1;i<n;i++)
	{
		ll aaaaa=a[i];
		if(a[i]!=a[i+1])
		{
			a[i]=a[i+1];
//			cout<<k<<" "<<a[i+1]<<" "<<a[i]<<'\n';
			dfs(step+1,k-a[i+1]+aaaaa);
			a[i]=aaaaa;		
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
			tpa=0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		if(a[2]-a[1]!=a[i]-a[i-1])
			tpb=0;
	}
	dfs(0,m);
	cout<<ans;
	return 0;
}
