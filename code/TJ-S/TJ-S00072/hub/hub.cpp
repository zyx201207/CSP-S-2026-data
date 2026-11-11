#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,a,b,ans;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n,k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>a>>b;
			ans=min(ans,a+b);
		}
		cout<<ans<<endl;
	}
	return 0;
}
