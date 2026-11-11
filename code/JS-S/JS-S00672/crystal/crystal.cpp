#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 500005
int n;
ll m;
ll a[N];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	ll nw=0;
	while(r<=n)
	{
		r++;
		nw+=(r-l)*(a[r]-a[r-1]);
		while(nw>m)nw-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
