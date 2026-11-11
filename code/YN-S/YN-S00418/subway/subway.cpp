#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,val[N];
vector<int> g[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	while(q--)
	{
		cout<<rand()%1e9<<'\n';
	}
	return 0;
}