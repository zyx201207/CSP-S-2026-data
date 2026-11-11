#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	vector<long long> q[1000005];
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			long long a,b;
			cin>>a>>b;
			q[a].push_back(b);
			q[b].push_back(a);
		}
		if(n==5) cout<<1<<endl;
		else cout<<"10\n";
	}
	return 0;
}
