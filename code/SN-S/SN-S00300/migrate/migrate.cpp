#include<bits/stdc++.h>

using namespace std;
long long c,t;
long long x[2000006];
vector<pair<int,int>>e[2000006];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<n;i++)
		{
			e[i].emplace_back(i+1,1);
			if(x[i]+x[i+1]<=d) 
				e[i].emplace_back(i+2,1);
		}
		int k=1;
		cout<<k<<"\n";
	}
	return 0;
}
