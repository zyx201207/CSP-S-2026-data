#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl "\n"
using pii=pair<int,int>;
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast;
	cin>>n>>m;
	vector<int>a(n+1);
	ll cnt;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a.begin()+1,a.end()+1,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==n)
	{
		cnt=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	ll ans=-1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll x=a[i]&a[j];
			ans=max(ans,x);
		}
	}
	cout<<ans;
	return 0;	
}