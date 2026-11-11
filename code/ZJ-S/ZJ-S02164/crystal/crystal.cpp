#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n,m;
ll a[N];
queue<ll> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll cur=0,strd=a[1],ans=1;
	q.push(a[1]);
	for(int i=2;i<=n;i++)
	{
		cur+=(a[i]-strd)*q.size();
		q.push(a[i]);
		strd=a[i];
		while(cur>m)
		{
			cur-=(strd-q.front());
			q.pop();
		}
		ans=max(ans,(ll)q.size());
	}
	printf("%lld",ans);
	return 0;
}
/*

*/