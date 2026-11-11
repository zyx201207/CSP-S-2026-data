#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
#define ll long long
ll m,a[N];
bool f(int j)
{
	ll c=m;
	for(int i=1;a[j]>a[i];++i)
	{
		c-=a[j]-a[i];
		if(c<0ll)return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int s=0,mx=0;
	for(int i=1;i<=n;++i)
	    if(a[i]==a[i-1])++s;
	    else
	    {
	    	mx=max(mx,s+1);
	    	s=0;
		}
	int l=1,r=n;
	while(l<=r)
	{
		int md=(r+l)/2;
		if(f(md))
		{
			ans=md;
			l=md+1;
		}
		else r=md-1;
	}
	cout<<max(ans,mx);
	return 0;
}

