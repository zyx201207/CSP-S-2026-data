#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=500020;
LL a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	LL i,j;
	LL n,m;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	LL ans=1,cnt=1,k=1;
	for (i=2;i<=n;i++)
	{
		while (k<i&&m<cnt*(a[i]-a[i-1]))
		{
			m+=(a[i-1]-a[k]);k++;
			cnt--;
		}
		m-=cnt*(a[i]-a[i-1]);
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
