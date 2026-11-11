#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>=4&&a[i]-a[i-2]<=d&&a[i]-a[i-3]>d) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


