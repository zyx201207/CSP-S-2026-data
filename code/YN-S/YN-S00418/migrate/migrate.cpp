#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int c,t;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--)
	{
		cout<<rand()%1e9<<'\n';
	}
	return 0;
}