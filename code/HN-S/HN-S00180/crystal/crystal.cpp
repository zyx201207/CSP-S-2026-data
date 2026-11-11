#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a.begin(),a.end());
	vector<long long> inv(n+1,0);
	for(int i=2;i<=n;++i)
	{
		long long diff=a[i]-a[i-1];
		if(diff==0)
		{
			inv[i]=inv[i-1];
		} 
		else inv[i]=diff+inv[i-1]+diff*(i-2);
		if(inv[i]>m) 
		{
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
