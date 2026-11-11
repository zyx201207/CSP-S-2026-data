#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=1e1+10;
int c,t,a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		n=n/2;
		cout<<n*(n-1)<<endl;
	}
	return 0;
}
//gunmugunmugunmu
