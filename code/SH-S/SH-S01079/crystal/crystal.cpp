#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 5e5+9;

ll n,m;
ll a[maxn];
ll ans;

void solve()
{
	ans=1;
	
	sort(a+1,a+1+n);
	
	ll sum=0;
	ll l=1;
	for(ll r=1;r<=n;++r)
	{
		//扩右
		sum+=a[r];
		//缩左
		while( l<r && a[r]*(r-l+1) > sum+m ) //想要的>可达的
		{
			sum-=a[l];
			++l;
		}
		ans=max(ans,(r-l+1));
	}
	
	return ;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&a[i]);
		
	solve();
	printf("%lld",ans);
	
	return 0;
}
