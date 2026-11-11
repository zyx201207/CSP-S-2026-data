#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define lowbit(x) (x)&(-x)
#define pii pair<int,int>
using namespace std;
const int N=2e6;
const int inf=0x3f3f3f3f3f;
int c,n,m,d,q;
int w[N];
inline void init()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int k;
	while(n--)
	{
		cin>>k;
		k*=2;
		while(k--)
		{
			int ww;
			cin>>ww;
		}
	}
}
inline void solve()
{
	init();
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<2*(w[l]+w[r]);
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
