#include <bits/stdc++.h>
#define ll long long

const int MAXT = 1e5+5;
using namespace std;
ll c,t;
vector<ll>x;
ll n,d;
ll ans[MAXT];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;

	cout<<x.size();
	int t1=t;
	while(t1--)
	{
		x.clear();
		cin>>n>>d;
		for(int i=1; i<=n; i++)
		{
			int x1;
			cin>>x1;
			x.push_back(x1);
		}
		
		
	}
	int an=rand() % (1+20);

	
	for(int i=1; i<=t; i++)
	{
		cout<<(an+i%3/an*an+abs(an*t*c+c))%20<<endl;
	}
	return 0;
}
