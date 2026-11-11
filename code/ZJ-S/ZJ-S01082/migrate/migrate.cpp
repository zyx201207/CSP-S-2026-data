#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<max(n-d*2LL+1LL,0LL)<<endl;
	}
	return 0;
}
