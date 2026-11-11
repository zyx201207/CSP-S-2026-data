#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2000010;
ll c,t,n,d,x[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		cout<<(x[1]+x[n])/2;
	}
	return 0;
}

