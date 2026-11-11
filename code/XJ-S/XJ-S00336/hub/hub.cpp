#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n;
		long long k,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			ans+=x;
		}
		cout<<(ans*n/2)%k<<'\n';
	}
	return 0;
}
