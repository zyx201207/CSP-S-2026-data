#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t,n;
	ll island_position[200005],d,distance;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>island_position[j];
		}
		distance=island_position[2]-island_position[1];
		if(d>=(2*distance))
		{
			cout<<n/2<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}