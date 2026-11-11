#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e5+50;
ll a[M];
//ll vs[M];
//priority_queue<ll,vector<ll>,greater<ll> >q;
ll cha[M];
ll sum[M];
ll s[M];
ll n,m;
//ll ans=1;
//ll cnt=0;
/*void dl(ll u,ll i)
{
	if(!q.empty()&&a[i]-a[i-1]<u&&cnt+a[i]-a[i-1]>m)
	{
		ans-=1;
		cnt-=q.top();
		q.pop();
	}
}*/
/*ll rd()
{
	char c=getchar();
	ll res=c-'0';
	while(c!=' '&&c!='\n')
	{
		c=getchar();
		res=10*res+(c-'0');
	}
	return res;
}*/
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		ll u;
		cin>>u;
		a[i]=u;
	}
	for(ll i=2;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
	}
	sort(cha+1,cha+n+1);
	for(ll i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+cha[i];
		s[i]=s[i-1]+sum[i];
		if(s[i]>(ll)m)
		{
			cout<<i-1;
			return 0;
		}
	}
	/*q.push(0);
	for(int i=2;i<=n;i++)
	{
		ll u=q.top();
		dl(u,i);
		q.push(a[i]-a[i-1]);
		ans+=1;
		cnt+=a[i]-a[i-1];
		ll o=q.size()-2;
		cnt+=(max((ll)0,o))*(a[i]-a[i-1]);
		cout<<cnt<<"fsd";
		while(!q.empty()&&q.top()>a[i]-a[i-1]&&cnt>m)
		{
			cnt-=q.top();
			ans-=1;
			q.pop();
			cout<<cnt<<endl;
		}
	}
	cout<<ans;*/
}/*
5 8
-3 -1 2 2 7
5 8
-5 -1 7 9 12
*/
