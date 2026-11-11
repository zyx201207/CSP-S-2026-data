#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 3e6+7; const int inf = 1e18+7;
int c,T,n,k;
int u,v;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		rep(i,1,n-1) cin>>u>>v;
		cout<<k-1<<endl;
	}
	return 0;
}
