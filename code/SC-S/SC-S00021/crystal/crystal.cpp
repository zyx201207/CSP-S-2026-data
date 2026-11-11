#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=5.1e5;
//滑动窗口
int n;
ll m;
ll a[MAX];
ll q[MAX];
int ans,l,r;
#define sub
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifdef sub
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		q[i]=q[i-1]+a[i];
	l=r=1;
	ll t=0;
	while(r<=n)
	{
		if(t+a[r]-a[r-1]+(r-l-1)*(a[r]-a[r-1])<=m)
			t+=a[r]-a[r-1]+(r-l-1)*(a[r]-a[r-1]),r++;
		else
			t-=a[r-1]-a[l],l++;
		ans=max(ans,r-l);
	}
	cout<<ans;
}