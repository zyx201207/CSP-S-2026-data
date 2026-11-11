#include<bits/stdc++.h>
using namespace std;
int c,t,a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a;
		cout<<max(0,n-m*2+1)<<"\n";
	}
	return 0;
}
