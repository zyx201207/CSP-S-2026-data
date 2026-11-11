#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
ll n,m,a[N],now[N],l,r,len,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		now[i]=a[i+1]-a[i];
	}
	l=1,r=1,len=now[1];
	while(l<=r&&r<=n-1)
	{
		while(l<=r&&len>m)
		{
			len-=(a[r+1]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
		len+=now[r]*(r-l+1);
	}
	cout<<ans+1<<"\n";
	return 0;
}