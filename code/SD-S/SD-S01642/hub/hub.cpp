#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=2e5+5;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			ans+=u+v;
		}
		cout<<ans%n<<"\n";
	}
	return 0;
}
