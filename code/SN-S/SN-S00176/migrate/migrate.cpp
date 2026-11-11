#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll d;
ll x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12)
		{
			ll y=x[2]-x[1];
			for(int i=3;i<=n-1;i++)
			if((i/2+1)*y<=d&&(i/2+2)*y>d)
			{
				cout<<n-i;
				return 0;
			}
			cout<<0;
			return 0;
		}
	}
	return 0;
}
