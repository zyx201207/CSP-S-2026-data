#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long zuo=0,you=n;
	while(zuo<=you)
	{
		long long t=(zuo+you)/2,he=0;
		for(int i=1;i<=t;i++)
			he+=a[t]-a[i];
		if(m>=he)
		{
			ans=t;
			zuo=t+1;
		}
		else
		{
			you=t-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
