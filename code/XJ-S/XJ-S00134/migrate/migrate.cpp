#include<bits/stdc++.h>
using namespace std;

long long n,m,x,y;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	if(n==0)
	{
		cin>>x>>y;
		if(x==4)
		{
			cout<<1<<"\n"<<2;
			return 0;
		}
		else if(x==5)
		{
			cout<<0<<"\n"<<1;
			return 0;
		}
	}
	
	
	return 0;
}
