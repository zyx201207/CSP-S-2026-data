#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll> >
using namespace std;
ll c,n,m,d,q,arr[500505],ans,a[500505],t[500505],fa[500505];
vector<pll> vt_x[505],vt_l[500505];
priority_queue<plll,vector<plll>,greater<plll> > pq,pq1; 
ll gr(ll x)
{
	if(fa[x]==x) return x;
	else return fa[x]=gr(fa[x]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+n;i++)
	{
		fa[i]=i;
		if(i>m) continue;
		cin>>arr[i];
	}
	for(int i=1+m;i<=n+m;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			vt_l[a[j]].push_back({i,t[j]});
			vt_x[i].push_back({a[j],t[j]});
			fa[a[j]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(vt_l[i].size()>=2)
		{
			for(int ii=0;ii<vt_l[i].size();ii++)
			{
				if(ii>=1)
				{
					pq.push({vt_l[i][ii-1].second+vt_l[i][ii-1].second,{vt_l[i][ii-1].first,vt_l[i][ii].first} });
				}
			}
		}
	}
	ll g=0;
	while(q--)
	{
		g++;
		ll dx,dy,f=0;
		cin>>dx>>dy;
		if(g%2==1)
		{
			while(!pq.empty())
			{
				if(gr(dx)==gr(dy)&&f==0)
				{
					cout<<ans+arr[dx]+arr[dy];
					f=1;
				}
				ll ttt=pq.top().first,x=pq.top().second.first,y=pq.top().second.second;
				pq.pop();
				x=gr(x),y=gr(y);
				if(x!=y)
				{
					ans+=ttt;
					fa[x]=y;
				}
				pq1.push({ttt,{x,y} });
			}
		}
		else
		{
			while(!pq1.empty())
			{
				if(gr(dx)==gr(dy)&&f==0)
				{
					cout<<ans+arr[dx]+arr[dy];
					f=1;
				}
				ll ttt=pq1.top().first,x=pq1.top().second.first,y=pq1.top().second.second;
				pq1.pop();
				x=gr(x),y=gr(y);
				if(x!=y)
				{
					ans+=ttt;
					fa[x]=y;
				}
				pq.push({ttt,{x,y} });
			}
		}
	}
	return 0;
}