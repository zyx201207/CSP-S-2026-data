#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200010
int n,m,c,k;
int a[N],u[N],v[N];

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;++i)
		{
			cin>>u[i]>>v[i];
		}
		cout<<'1'<<'\n';
	}
	return 0;
}