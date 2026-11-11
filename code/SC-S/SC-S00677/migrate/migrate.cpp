#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+10;

int a[maxn];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int s=a[2]-a[1];
		if(d<2*s)
		{
			cout<<0<<'\n';
			break;
		}
		cout<<n-3<<'\n';
	}
	
	return 0;
}