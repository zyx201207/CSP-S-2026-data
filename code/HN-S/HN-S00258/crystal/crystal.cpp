#include<bits/stdc++.h>
using namespace std;
long long a[500005],s=1,t=0,ans=0;
int main()
{
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		s=1;
		t=0;
		for(int j=i-1;j>=1;j--)
		{
			t=t+a[i]-a[j];
			if(t>m) break;
			s++;
		}
		ans=max(s,ans);
	}
	cout<<ans;
	return 0;
}
