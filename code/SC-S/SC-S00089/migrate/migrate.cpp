#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int c,t,n,d,a[N],dis[N],cnt[N];

signed main()
{
	int ans=0;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<n-d-1<<'\n';
	}
//	cout<<ans;
	return 0;
}