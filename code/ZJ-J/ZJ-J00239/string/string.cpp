#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	vector<long long> a(n+1,0);
	vector<char> s(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	long long ans=0,l=1,r=n;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			ans+=min(a[l],a[r]);
		}
		if(a[l]<a[r])
		{
			a[r]-=a[l];
			l++;
		}
		else
		{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}