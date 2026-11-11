#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500001];
bool ck(int x)
{
	int t=0;
	int h=1;
	for(int i=1;i<=x;i++)
	{
		t+=a[h]-a[i];
	}
	if(t<=m)return true;
	for(int i=x+1;i<=n;i++)
	{
		t-=(a[h]-a[h+1])*(x-1);
		t+=(a[h+1]-a[h+x]);
		h++;
		if(t<=m)return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(ck(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

