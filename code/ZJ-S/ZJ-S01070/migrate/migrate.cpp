#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,xy[20101010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>xy[i];
		}
		if(d<2*(xy[n]-xy[n-1]))
		{
			cout<<0<<"\n";
			continue;
		}
		int sum=n/(d/(xy[n]-xy[n-1])*2);
		cout<<sum<<"\n";
	}
} 
