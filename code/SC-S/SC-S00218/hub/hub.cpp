#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x,y;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
		}
		cout<<(n-k)/8<<"\n";
	}
	return 0;
}