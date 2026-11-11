#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
using namespace std;
int n,ans=1;
ull m;
ll a[500010],cf[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
	int l=1,r=2,cnt=1;
	ull t=0,th=0;
	while(l<n&&r<=n)
	{
		t+=1ULL*cf[r]*cnt;
		th+=cf[r];
		if(t>m)
		{
			t-=1ULL*cf[r]*cnt;
			th-=cf[r];
			t-=th;
			l++;
			cnt--;
			th-=cf[l];
		}
		else
		{
			r++;
			cnt++;
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}