#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long m;
vector<long long> v,zhui;
bool check(int mu)
{
	for(int i=1;i+mu-1<=n;i++)
	{
		int j=i+mu-1;
		if(zhui[j]-zhui[i-1]+m>=v[j]*mu) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	v.resize(n+1);
	zhui.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin()+1,v.end());
	for(int i=1;i<=n;i++)
	{
		zhui[i]=zhui[i-1]+v[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
