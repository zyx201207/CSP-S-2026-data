#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+10;
ll n,m,sxt,a[N],mp[N],js[N],ans[N];
vector<ll>q;
ll find(ll l,ll r,ll x)
{
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(q[mid]>x) l=mid+1;
		else if(q[mid]<x) r=mid-1;
		else return mid;
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		js[a[i]]=i;
		if(a[i]<a[i-1]) sxt=1;
	}
	if(sxt==0)//特判a[i]<=a[i+1]<=a[i+1]<=...<=a[n] 
	{
		for(ll i=1;i<=m;i++) cout<<js[i]<<' ';
		return 0; 
	} 
	for(ll i=1;i<=n;i++)
	{
		memset(mp,-1,sizeof(mp));
		q.clear();
		for(ll j=i;j<=n;j++)
		{
			if(mp[a[j]]!=-1)//a[j]存在 
			{
				for(ll k=mp[a[j]]+1;k<q.size();k++) mp[q[k]]=-1;//位置变为-1 
				q.erase(q.begin()+mp[a[j]],q.end());//收走从a[j]位置往右的所有数 
			}
			q.push_back(a[j]);//把a[j]加入 
			mp[a[j]]=q.size()-1;//位置 
		}
		for(ll j=1;j<=m;j++) if(mp[j]!=-1) ans[j]++;
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
}
