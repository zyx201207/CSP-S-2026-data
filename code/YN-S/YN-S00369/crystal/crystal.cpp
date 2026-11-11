#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=5e5+5;
ll n,ans,m,cnt;
ll a[MAXN];
priority_queue<ll,vector<ll>,greater<ll>>q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		cnt+=(a[i]-a[i-1])*1LL*q.size();
		q.emplace(a[i]);
		if(cnt>m)
			while(!q.empty()&&cnt>m)
				cnt-=a[i]-q.top(),q.pop();
		if(!q.empty())
			ans=max(ans,(ll)q.size());
	}
	cout<<ans<<'\n';
	return 0;
}
