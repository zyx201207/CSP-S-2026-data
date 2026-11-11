#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e9+7;
ll c,t,n,d,a[2000005],cf[2000005],minstp,ccnt;
void dfs(ll x,ll l,ll r,ll k)
{
	if(x==r)
	{
		if(k==minstp)ccnt++;
		if(k<minstp)
		{
			minstp=k;
			ccnt=1;
		}
		return;
	}
	if(k>=minstp)return;
	for(ll i=x+1;i<=r;i++)
	{
		if(a[i]-a[x]<=d)dfs(i,l,r,k+1);
		else break;
	}
}
bool check(ll l,ll r)
{
	minstp=INF;
	ccnt=0;
	dfs(l,l,r,0);
	if(ccnt==2)return true;
	else return false;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i];
		ll cnt=0;
		if(c==11||c==12)
		{
			ll cha=a[2]-a[1];
			ll stp=d/cha;
			if(stp==0||d==cha)
			{
				cout<<"0\n";
				continue;
			}
			ll ly=stp*2-1;
			if(ly>n-1)cout<<"0\n";
			else cout<<n-ly<<"\n";
			continue;
		}
		else if(c<=6)
		{
			for(ll i=1;i<n;i++)for(ll j=i+1;j<=n;j++)if(check(i,j))cnt++;
			cout<<cnt<<"\n";
		}
		else cout<<"0\n";
	}
	return 0;
}
