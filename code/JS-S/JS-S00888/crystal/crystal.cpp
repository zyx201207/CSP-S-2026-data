#include<bits/stdc++.h>
#define ll long long
const ll N=500005;
using namespace std;
int n,m;
ll a[N];
queue<ll>q;
ll cost;
ll pre_pos;
ll ans;
int main()
{
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ll now_pos=a[i];
		if(i!=1)
		{
			cost+=(ll)q.size()*(now_pos-pre_pos);
		}
		q.push(i);
		pre_pos=now_pos;
		while(!q.empty()&&cost>m)
		{
			ll last_pos=a[q.front()];
			cost-=now_pos-last_pos;
			q.pop();
		}
		ans=max(ans,(ll)q.size());
	}
	cout<<ans;
	return 0;
}
