#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>=4)
			{
				if((x[i]-x[i-1])<d&&(x[i]-x[i-2])<=d&&(x[i]-x[i-3])>d) ans++;
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
