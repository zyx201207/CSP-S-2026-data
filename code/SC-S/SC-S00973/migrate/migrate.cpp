#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t; cin>>c>>t;
	while(t--)
	{
		int n,d,z=0; cin>>n>>d;
		vector<int> a(n);
		for(auto &x:a) cin>>x;
		for(int x=0;x+2<n;x++)
		{
			if(a[x+2]>a[x]+d) continue;
			for(int y=x+3;y<n;y++)
			{
				if(not(y<n))
					break;
				if(a[y]<=a[x]+d) continue;
				if(a[y]>a[x+1]+d) break;
				z++;
			}
		}
		cout<<z<<'\n';
	}
	cout<<'\n';
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/