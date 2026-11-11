#include<bits/stdc++.h>
using namespace std;


signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int o,t;
	cin>>o>>t;
	int a[100005];
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d/(a[2]-a[1])==1)
		{
		cout<<0<<endl;
			
		}
		else cout<<1<<endl; 
	}
	return 0;
 } 
