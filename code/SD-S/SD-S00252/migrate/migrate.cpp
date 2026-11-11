#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) 
		{
			int x;
			cin>>x;
		}
		int t=rand()%n+1;
		cout<<t<<"\n";
	}
	return 0;
}
