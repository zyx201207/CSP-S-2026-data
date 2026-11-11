#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000006],sum; 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			if(i+d<=n)
			{
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
