#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		int x,y;
		cin>>x>>y;
		for(int i=3;i<=n;i++)
		{
			int z;
			cin>>z;
		}
		int s=abs(x-y);
		if(d>=2*s&&(s*(n-1))>=d)cout<<n+1-2*(d/s)<<endl;
		else cout<<0<<endl;
	}
	return 0;
} 
