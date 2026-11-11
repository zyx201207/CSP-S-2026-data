#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
贪心 
*/
ll n,m;
ll a[200100];
vector<ll> v[30];
vector<ll> zj,bs;
bool cmp(ll a,ll b)
{
	for(ll j=30;j>=0;j--)
	{
		if((a&(1<<j))&&(!(b&(1<<j)))) return true;
		if((b&(1<<j))&&(!(a&(1<<j)))) return false;
	}
	return true; 
}
void calc(ll x)
{
	ll ans=INT_MAX;
//	cout<<ans<<"\n";
	sort(v[x].begin(),v[x].end(),cmp);
	ll gs=0;
//	cout<<v[x].size()<<"\n";
	for(auto it:v[x])
	{
		ans&=(it);
//		cout<<it<<" ";
		gs++;
		if(gs>m) break;
	}
	cout<<ans<<"\n";
}
void dfs(ll sl)
{
	zj=v[sl];
	bs=zj;
	for(ll j=30;j>=0;j--) v[j].clear();
	for(ll i=0;i<bs.size();i++)
	{
		ll it=bs[i];
		for(ll j=0;j<=30;j++)
		{
			if(it&(1<<j)) v[j].push_back(it);
		}
//		cout<<"\n";
	}
//	cout<<"---------------\n";
	ll wz=-1;
	for(ll j=sl-1;j>=0;j--)
	{
		if(v[j].size()<m) continue; 
		if(v[j].size()==m) //find
		{
			
			calc(j);
			return;
		}
		wz=j;
		break;
	}
	//wz中选
//	cout<<v[sl].size()<<"\n";
	if(wz==-1) //哪个都可以
	{
		v[sl]=bs;
//		cout<<v[sl].size()<<'\n';
		calc(sl);
		return;
	} 
	cout<<wz<<"\n";
	dfs(wz);
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		ll ma;
		for(ll j=0;j<=30;j++)
		{
			if(a[i]&(1<<j)) v[j].push_back(a[i]),ma=(1<<j);
		}
//		if(ma>131072) cout<<ma<<"\n";
	}
	ll wz=0;
	for(ll j=30;j>=0;j--)
	{	
//		cout<<v[j].size()<<"\n";
		if(v[j].size()<m) continue; 
		if(v[j].size()==m) //find
		{
//			cout<<j<<' '<<m<<' '<<"\n";
			calc(j);
			return 0;
		}
	
		wz=j;
//		break;
	}
	//wz中选 
	dfs(wz);
	return 0;
}

