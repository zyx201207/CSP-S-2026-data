#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,t;
int a[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d>=a[n])
		{
			cout<<0<<'\n';
		}
	}
	return 0;
}
