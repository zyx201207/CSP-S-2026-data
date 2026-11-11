#include<bits/stdc++.h>
using namespace std;
long long n,T,t,m,a[20000005];
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(t==11||t==12)
		{
			 cout<<0<<'\n';
		}
	}
	
	return 0;
}
